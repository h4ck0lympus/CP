# Notes 

## 'include <bits/stdc++.h>'

### How to increase precision 

We can use : 
```c++
float n ; 
cout << fixed << setprecision(5) << pi << endl ; // get precision digit enter to precision digit entered in the bracket 
```

### tolower() method of char  

Convert upper case char to lowercase 

### sort array 

sorts array using merge sort algo in the bg. 

Just use `sort(<starting address of arr>, <address of last element>)` 

### `auto` datatype initializer 

`auto` will automatically deduce the type of variable by its initializer. Generally used in for loops.  

### `map` in cpp (Dictionary of cpp)

Generaral array which consists of key value pair. 

Create a map with keys as strings and value as int. 

```c++
map<string, int> m  ; 
m["key1"] = 1 ; 
m["key2"] = 2 ; 
cout << m["key1"] << "\n" ; // 1 

// to print every key value pair 

for (auto i: m) {
    cout << i.first << " " << i.second << "\n" ; 
}

// to check if key exits 

if (m.count("key3")) {
    cout << m["key3"] << "\n" ; // no output 
}
``` 

### vectors (dynamic array) 

#### using pairs in vectors 

```cpp 
vector<pair<int,int>> v ; 
v.push_back(make_pair(100,200)) ; 
// we can also sort it : 
sort(v.begin(),v.end()) ; 
```
