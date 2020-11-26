### topological sort

维护一个入度数组和出度邻接表，使用queue维护一个入度为零的node集合
可以sort按照依赖关系输出，可以判断DAG是否有环

