import os
import sys
import argparse

sstdump_tool_path = "/users/nithinv/rocksdb/sst_dump"
  
def read_file(input_path, output_path):
    os.system(sstdump_tool_path + " --file=" + input_path + \
             " --command=scan --output_hex > " + output_path)

def read_ssts_hex(input_path, output_path):
    for ele in os.listdir(input_path):
        path = os.path.join(input_directory, ele)
        if os.path.isdir(path):
            read_ssts_hex(path, output_path)
        elif ele.endswith(".sst"):
            full_path = os.path.join(input_path, ele)
            output_path = output_directory + full_path.replace("/", "_") + ".temp"
            read_file(full_path, output_path)

def parse_file(input_path, output_path):
    if os.path.exists(output_path):
        os.remove(output_path)
    with open(input_path) as f:
        lines = list(f.read().splitlines())
        print(len(lines))
        for line in lines[3:]:
            key = line.split()[0]
            os.system("mok " + key + " >> " + output_path)

def mok_files(input_path):
    for ele in os.listdir(input_path):
        if ele.endswith(".temp"):
            full_path = os.path.join(input_path, ele)
            output_path = output_directory + full_path.replace("/", "_") + ".output"
            parse_file(full_path, output_path)

def get_sst_properties(input_directory, output_file):
    output_path = os.path.join(input_directory, output_file)
    if os.path.exists(output_path):
        os.remove(output_path)
    for ele in os.listdir(input_directory):
        if ele.endswith(".sst"):
            input_path = os.path.join(input_directory, ele)
            os.system(sstdump_tool_path + " --file=" + input_path + \
             " --show_properties >> " + output_path)
            os.system("echo '\n' >> output_path")

def parse_args():
    parser = argparse.ArgumentParser()
    parser.add_argument("--command", type=str, default="parse_keys")
    parser.add_argument("--input_directory", type=str)
    parser.add_argument("--output_directory", type=str)
    args = parser.parse_args()
    return args

if __name__ == "__main__":
    args = parse_args()
    command, input_directory, output_directory = args.command, args.input_directory, \
    args.output_directory
    print(command, input_directory, output_directory)
    if command == "parse_keys":
        read_ssts_hex(input_directory, output_directory)
        # mok_files(output_directory)
    elif command == "sst_properties":
        get_sst_properties(input_directory, "sst_properties.output")
    # read_file(input_directory + "tikv-20160/db/000054.sst", output_directory + "test")
    # parse_file(output_directory + "test", output_directory + "test1")