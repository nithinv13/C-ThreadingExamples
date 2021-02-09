package main

import (
	"fmt"
	"errors"
	"math"
)

// Struct
type person struct {
	name string
	age int
}

func main() {
	// Automatic inference of variable
	x := 5
	// Explicit assignment of variable
	var y int = 7
	var z = x + y
	fmt.Println(z)
	fmt.Println("Hello world")
	if x > 6 {
		fmt.Println("Number is greater than 6")
	} else {
		fmt.Println("Number is lesser than 6")
	}

	// Arrays
	// var a [5]int
	a := [5]int{2, 1, 3, 4, 5}
	fmt.Println(a)

	// Slices do not have fixed size: []
	b := []int{5, 4, 3, 2, 1}
	b = append(b, 13)
	fmt.Println(b)

	// Map
	// map[string]int 
	vertices := make(map[string]int)

	vertices["triangle"] = 2
	vertices["square"] = 3
	vertices["dodecagon"] = 12
	delete(vertices, "square")

	fmt.Println(vertices)

	// Loops
	for i := 0; i < 5; i++ {
		fmt.Println(i)
	}

	// For loop with range
	arr := []string{"a", "b", "c"}
	for index, value := range arr {
		fmt.Println("index:", index, "value:", value)
	}

	// For loop with maps
	m := make(map[string]string)
	m["a"] = "alpha"
	m["b"] = "beta"
	for key, value := range m{
		fmt.Println("key:", key, "value:", value)
	}

	fmt.Println(sum(5, 5))

	result, err := sqrt(-16)
	
	if err != nil {
		fmt.Println(err)
	} else {
		fmt.Println(result)
	}

	// Struct
	p := person{name: "Jake", age: 21}
	fmt.Println(p.age)

	// Pointer
	i := 7
	fmt.Println(&i)

	inc(&i)
	fmt.Println(i)
}

func sum(x int, y int) int {
	return x + y
}

// Return can be multiple values
func sqrt(x float64) (float64, error) {
	if x < 0 {
		return 0, errors.New("Undefined for negative numbers")
	}

	return math.Sqrt(x), nil
}

func inc(x *int) {
	*x++
}