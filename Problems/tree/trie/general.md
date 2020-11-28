## 定义

在计算机科学中，trie，又称前缀树或字典树，是一种有序树，用于保存关联数组，其中的键通常是字符串。与二叉查找树不同，键不是直接保存在节点中，而是由节点在树中的位置决定。**一个节点的所有子孙都有相同的前缀，也就是这个节点对应的字符串，而根节点对应空字符串**。一般情况下，不是所有的节点都有对应的值，只有叶子节点和部分内部节点所对应的键才有相关的值。

trie中的键通常是字符串，但也可以是其它的结构。trie的算法可以很容易地修改为处理其它结构的有序序列，比如一串数字或者形状的排列。比如，bitwise trie中的键是一串位元，可以用于表示整数或者内存地址。

## 性质
    根节点不包含字符，除根节点外每一个节点都只包含一个字符。

    从根节点到某一节点，路径上经过的字符连接起来，为该节点对应的字符串。

    每个节点的所有子节点包含的字符都不相同。

## 应用场景优缺点

    典型应用是用于统计和排序大量的字符串（但不仅限于字符串），所以经常被搜索引擎系统用于文本词频统计。它的优点是：最大限度地减少无谓的字符串比较，查询效率比哈希表高。

    Trie的核心思想是空间换时间。利用字符串的公共前缀来降低查询时间的开销以达到提高效率的目的。

    Trie树也有它的缺点,Trie树的内存消耗非常大.当然,或许用左儿子右兄弟的方法建树的话,可能会好点.

## 常见操作


插入insert
查找 search
比较前缀 startWith

    1. 插入
    1),从根节点查找第一个字母ch1存在的TrieNode
    如未找到,则新建一个TrieNode,将<ch1,TrieNode>映射关系保存在根节点中
    如找到,继续向下cha'r插入
    2),从上一步找到的TrieNode查找ch2存在的TrieNode
    如未找到,则新建一个TrieNode,将<ch1,TrieNode>映射关系保存在根节点中
    如找到,继续向下插入
    直至插入最后一个字母chn, 这时候将最后的TrieNode标记为字符串结束

    2. 查找
    1)从根节点查找第一个字母ch1,如果ch1对应的TrieNode未找到,则直接返回false
    否则,从找到的TrieNode找出第二个ch2对应的TrieNode继续向下查找
    直至找到最后一个字符串对应的TrieNode, 如果最后一个TrieNode对应的字符串结束为true则返回true,否则false

    3. 比较前缀
    比较前缀的过程和查找过程类似,唯一不同的是,最后一个字符对应的TrieNode不用判断是否是字符串结束

```java
class TrieNode {
    boolean isLeaf;
    Map<Character,TrieNode> content;
    // Initialize your data structure here.
    public TrieNode() {
        content = new HashMap<Character,TrieNode>();
    }
}

public class Trie {
    private TrieNode root;

    public Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    public void insert(String word) {
        if(word == null || word.length() == 0){
            return;
        }
        
        TrieNode node = root;
        TrieNode tempNode = null;;
        for(int i=0, len=word.length(); i<len; i++){
            Character c = word.charAt(i);
            tempNode = node.content.get(c);
            if(tempNode == null){
                tempNode = new TrieNode();
                node.content.put(c,tempNode);
            }
            node = tempNode;
        }
        node.isLeaf = true;
    }

    // Returns if the word is in the trie.
    public boolean search(String word) {
        if(word == null || word.length() == 0){
            return false;
        }
        
        TrieNode node = root;
        TrieNode tempNode = null;;
        for(int i=0, len=word.length(); i<len; i++){
            Character c = word.charAt(i);
            tempNode = node.content.get(c);
            if(tempNode == null){
                return false;
            }
            node = tempNode;
        }
        return node.isLeaf;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    public boolean startsWith(String prefix) {
        if(prefix == null || prefix.length() == 0){
            return false;
        }
        
        TrieNode node = root;
        TrieNode tempNode = null;;
        for(int i=0, len=prefix.length(); i<len; i++){
            Character c = prefix.charAt(i);
            tempNode = node.content.get(c);
            if(tempNode == null){
                return false;
            }
            node = tempNode;
        }
        return true;
    }
}

// Your Trie object will be instantiated and called as such:
// Trie trie = new Trie();
// trie.insert("somestring");
// trie.search("key");
```

```C++
class Trie
{
private:
	bool is_string = false;
	Trie* next[26] = { nullptr };
public:
	Trie() {}

	void insert(const string& word)//插入单词
	{
		Trie* root = this;
		for (const auto& w : word) {
			if (root->next[w - 'a'] == nullptr)root->next[w - 'a'] = new Trie();
			root = root->next[w - 'a'];
		}
		root->is_string = true;
	}

	bool search(const string& word)//查找单词
	{
		Trie* root = this;
		for (const auto& w : word) {
			if (root->next[w - 'a'] == nullptr)return false;
			root = root->next[w - 'a'];
		}
		return root->is_string;
	}

	bool startsWith(const string& prefix)//查找前缀
	{
		Trie* root = this;
		for (const auto& p : prefix) {
			if (root->next[p - 'a'] == nullptr)return false;
			root = root->next[p - 'a'];
		}
		return true;
	}
};
```

## 注意事项

1. 声明TrieNode成员public
2. search中必须判断最终节点是否是leaf
3. startwith不需要判断是否是leaf-09