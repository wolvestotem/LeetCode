# C++基础语法

## vector

## String

## unordered_map

## map

## unordered_set

## heap

默认max heap
```C++
vector<int> v{2,1,4,5};
make_heap(v.begin(),v.end());
v.push_back(10);
push_heap(v.begin(),v.end());
pop_heap(v.begin(),v.end());
v.pop_back();
int max = v.front();
bool t=is_heap(v.begin(),v.end());
```
小顶堆
```C++
bool func(int a, int b){
    return a>b;
}
make_heap(v.begin(),v.end());
```

## list
