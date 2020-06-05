# LeetCode weekly contest problems

### 1450 Number of students doing hw at a given time

Simple loop to find the result

### 1451 Rearange words in a sentence

本题在string输入、排序算法多个方面具有启发性，应该深入讨论。

**输入一个string sentence，获取每个分隔的words方法**

- 建立`vector<string>`,遍历每个`char`，`isspace()`时插入下一个`string`

```C++
    int j=0;
    for(int i=0;i<text.size();i++){
        if(isspace(text[i])){
            j++;
            word.push_back("");
        }
        else{
            word[j].push_back(text[i]);
        }
    }
```

- 建立`vector<string>`，使用`text.find_first_of(" ")`，找到后替换为'*',直到不再有space

```C++
int start(0);
while(text.find_first_of(" ")!=string::npos){
    int found = text.find_first_of(" ");
    text[found] = '*';
    word.push_back(text.substr(start,found-start));
    start = found+1;
}
word.push_back(start);
```

- **使用stringstream,自动输出删除空格后的内容**

```C++
stringstream ss(text);
string w;
while(ss>>w) word.emplace_back(w);
```

**STL排序算法的灵活使用**

本题目的在于稳定排序，已有方法`stable_sort`，也可以自己造`sort`

- stable_sort

```C++
stable_sort(word.begin(),word.end(),[](const string &a, const string &b){return a.size()<b.size();});
```

- sort

```C++
vector<pair<string,int>> word;
sort(word.begin(),word.end(),
[](const auto &a, const auto &b){return a.first.size()<b.first.size() || (a.first.size()==b.first.size() && a.second<b.second);});
```

- map

```C++
map<int,string> m;
while(ss>>w)
    m[word.size()] += word+" ";
```

### 1452 People Whose List of Favorite Companies Is Not a Subset of Another List

使用`includes`函数，检测一个有序列是否包含另一个有序列，返回`bool`类型

```C++
class Solution {
public:
    vector<int> peopleIndexes(vector<vector<string>>& favoriteCompanies) {
        //includes()
        vector<int> result;
        for(auto &tem:favoriteCompanies)
            sort(tem.begin(),tem.end());

        for(int i=0;i<favoriteCompanies.size();i++){
            bool f = false;;
            for(int j=0;j<favoriteCompanies.size();j++){
                if(j!=i)
                    f = includes(favoriteCompanies[j].begin(),favoriteCompanies[j].end(),favoriteCompanies[i].begin(),favoriteCompanies[i].end());
                if(f)
                    break;
            }
            if(!f)
                result.push_back(i);
        }
        return result;
    }
};
```
