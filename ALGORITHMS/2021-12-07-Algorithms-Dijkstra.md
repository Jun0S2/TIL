---
layout: post
title: "다익스트라 알고리즘"
date: 2021-12-07 12:07:57 +0900
categories: C++
---

## 최단거리 알고리즘

|      이름      | 간선의 가중치 |  시작점   |  도착점   |    시간복잡도    |
| :------------: | :-----------: | :-------: | :-------: | :--------------: |
|      BFS       |       1       |  한 정점  | 모든 정점 |      O(V+E)      |
|    Dijkstra    |    0 이상     |  한 정점  | 모든 정점 |     O(ElogV)     |
| Floyd-Warshall |    제약 x     | 모든 정점 | 모든 정점 | O(V<sup>3</sup>) |
|  Bellman-Ford  |    제약 x     |  한 정점  | 모든 정점 |     O(V x E)     |

## 다익스트라 알고리즘

### 요약

주로 최단 경로를 구하는 문제에서 양의 가중치가 주어졌을 때 사용

1. Input

   시작 정점과 그래프가 주어졌을 때 사용 가능 (제한 조건 - 가중치 0 이상)

2. Output

   시작점에서 모든 점까지의 최단 거리를 구함

3. 시간 복잡도

   O(E log V)

   - E: 간선의 개수
   - V : 정점의 개수

### Steps

1. Dist 배열 생성 및 INF 로 초기화
   <br>PriorityQueue에 (시작점, weight=0) 을 추가
2. 큐가 비면 종료
3. 비어있지 않을 경우
   - min(v,d)를 큐에서 poll
   - 연결된 모든 간선들을 통해서 다른 정점들에 대한 정보 갱신

## Examples

다익스트라 관련 문제 - 백준 1916 최소비용 구하기, 1753 최단경로, SWEA 보급로

### 백준 최소 비용 구하기

### Init

1. dist 배열
2. 문제의 input 저장할 자료구조
3. 큐에서 쓸 클래스 & input용 클래스

```java
static int dist[]; //distance 배열
static ArrayList<Edge>[] edges; //edges 담을 배열리스트
/*Class*/
static class Info{
	public int idx,dist;
	public Info(int idx,int dist) {
		this.dist=dist;
		this.idx=idx;
	}
}
static class Edge{
	public int to,weight;
	public Edge(int to,int weight) {
		this.to=to;
		this.weight=weight;
	}
}
```

### 다익스트라 메서드

#### dist 배열 INF 로 초기화

```java
for(int i = 1; i<=N; i ++) dist[i] = Integer.MAX_VALUE;
```

#### PriorityQueue 생성

Prioirity Queue 생성 & start index와 가중치(0) 삽입

```java
PriorityQueue<Info> pq = new PriorityQueue<>(Comparator.comparingInt(o->o.dist));
pq.add(new Info(start,0));
dist[start]=0;
```

#### 거리 갱신

```java
/*pq에 담긴 거리 정보들이 소진될때까지, 거리를 갱신*/
while(!pq.isEmpty()) {
	Info info = pq.poll();//pop
	if(dist[info.idx]!=info.dist)continue; //index 번째 dist 배열에 담긴 거리와, 방금 꺼낸 거리가 다르면 낡은 정보이므로 폐기시킴
		for(Edge e: edges[info.idx]) {		   //연결된 모든 간선들을 통해서 다른 정점에 대한 정보 갱신
		if(dist[info.idx]+e.weight>=dist[e.to])continue; //min distance가 아닐경우 넘김
		//Else
  	dist[e.to] = dist[info.idx] + e.weight ; //거리갱신
		pq.add(new Info(e.to,dist[e.to]));		 //갱신 후 큐에 넣음
	}
}
```

- dist 배열에 저장된 distance와 현재 새루트로 왔을 때의 distance값(prev weight + current weight) 중 min 값으로 갱신

<br>
<BR>
<br>
<hr>

### Source Codes

#### 백준 1916 최소비용 구하기

```java
public class BOJ_1916_최소비용구하기 {
	static int N,M;
	static int dist[]; //distance 배열
	static ArrayList<Edge>[] edges; //edges 담을 배열리스트

	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		N = Integer.parseInt(br.readLine()); //도시의 개수(정점)
		M = Integer.parseInt(br.readLine()); //버스의 개수(간선)
		dist = new int[N+1];				 //dist 배열
		edges = new ArrayList[N+1];			 //edges 담을 배열 리스트: each element : vertex -> containing to,weight
		for(int i = 1; i<=N ;i ++) edges[i] = new ArrayList<Edge>(); //empty arraylist

		for (int i=1;i<=M;i++) {			 //store input
			st = new StringTokenizer(br.readLine());
			int from = Integer.parseInt(st.nextToken());
			int to = Integer.parseInt(st.nextToken());
			int weight = Integer.parseInt(st.nextToken());
			edges[from].add(new Edge(to,weight));
		}
		st= new StringTokenizer(br.readLine());
		int start = Integer.parseInt(st.nextToken()); //시작지점
		int end = Integer.parseInt(st.nextToken());	  // 도착지점

		br.close();

		dijkstra(start);
		System.out.println(dist[end]);

	}
	/** Dijkstra method
	 * 	Steps
	 * 1. 배열 초기화 및 (start, 0) 을 자료구조에 pq에 저장
	 * 2. pq 가 empty될때까지 거리를 갱신
	 * 	- pq에서 꺼낸 정보가 최신 정보랑 다르면 폐기
	 * 	- else: 연결된 모든 간선들을 통해서 다른 정점들에 대한 정보를 갱신함
	 * */
	private static void dijkstra(int start) {
		/*dist 배열 초기화*/
		for(int i = 1; i<=N; i ++) dist[i] = Integer.MAX_VALUE;
		/*최소 힙 생성 : dist 순으로 정렬*/
		PriorityQueue<Info> pq = new PriorityQueue<>(Comparator.comparingInt(o->o.dist));
		/*init*/
		pq.add(new Info(start,0));
		dist[start]=0;

		/*pq에 담긴 거리 정보들이 소진될때까지, 거리를 갱신*/
		while(!pq.isEmpty()) {
			Info info = pq.poll();//pop
			if(dist[info.idx]!=info.dist)continue; //index 번째 dist 배열에 담긴 거리와, 방금 꺼낸 거리가 다르면 낡은 정보이므로 폐기시킴
			for(Edge e: edges[info.idx]) {		   //연결된 모든 간선들을 통해서 다른 정점에 대한 정보 갱신
				if(dist[info.idx]+e.weight>=dist[e.to])continue; //min distance가 아닐경우 넘김
				//Else
				dist[e.to] = dist[info.idx] + e.weight ; //거리갱신
				pq.add(new Info(e.to,dist[e.to]));		 //갱신 후 큐에 넣음
			}
		}
	}

	/*Class*/
	static class Info{
		public int idx,dist;
		public Info(int idx,int dist) {
			this.dist=dist;
			this.idx=idx;
		}
	}
	static class Edge{
		public int to,weight;
		public Edge(int to,int weight) {
			this.to=to;
			this.weight=weight;
		}
	}
}

```

#### 백준 1753 최단경로 구하기

```java
public class BOJ_1753_최단경로 {
	static int V,E;
	static int[] dist; //dist 배열
	static ArrayList<Edge>[] edges;
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		V = Integer.parseInt(st.nextToken());			//정점의 개수
		E = Integer.parseInt(st.nextToken());			//간선의 개수
		dist = new int[V+1];
		edges = new ArrayList[V+1];
		//edges에 empty list 삽입
		for(int i =1; i<=V;i++) {
			edges[i] = new ArrayList<Edge>();
		}
		int start = Integer.parseInt(br.readLine());
		//Input
		for(int i = 1; i<=E;i++) {
			st = new StringTokenizer(br.readLine());
			int from = Integer.parseInt(st.nextToken());
			int to = Integer.parseInt(st.nextToken());
			int weight = Integer.parseInt(st.nextToken());
			edges[from].add(new Edge(to,weight));
		}
		br.close();
		dijkstra(start);//vertext 가 1일때 부터 시작
		StringBuilder sb = new StringBuilder();
		for(int i =1 ; i<=V; i++) {
			sb.append(dist[i]==Integer.MAX_VALUE?"INF":dist[i]);
			sb.append("\n");
		}
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		bw.append(sb.toString());
		bw.flush();
		sb.setLength(0);


	}
	private static void dijkstra(int start) {
		//init:음수
		for(int i = 1 ; i<=V;i++) {
			dist[i]=Integer.MAX_VALUE;
		}
		//minHeap
		PriorityQueue<Info> pq = new PriorityQueue<>(Comparator.comparingInt(o->o.distance));//거리순으로정렬
		pq.add(new Info(start,0)); //시작index와 0
		dist[start]=0;//처음노드로 가는데 비용 0
		while(!pq.isEmpty()) {
			Info info = pq.poll();
			if(info.distance != dist[info.index])continue;//outdated
			for(Edge e : edges[info.index]) {		//연결된 모든 간선들 돌면서
				if(dist[e.to]<=dist[info.index]+e.weight)continue; //현재 가려는 루트가 더 비효율적임
				//Else:기존 dist 배열에 최단경로 업데이트
				dist[e.to]=dist[info.index]+e.weight;
				pq.add(new Info(e.to,dist[e.to]));
			}
		}
	}
	/*classes*/
	static class Edge{
		public int to,weight;
		Edge(int to, int weight){
			this.to = to;
			this.weight = weight;
		}
	}
	static class Info{
		public int index,distance;
		Info (int index,int distance){
			this.index = index;
			this.distance = distance;
		}
	}
}
```
