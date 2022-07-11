#include <iostream>
#include <stack>
#include <queue>
#include <string>

using namespace std;

class Vertex
{
public:
    Vertex(char lab)
    {
     Label=lab;
     wasVisited=false;
    }
    bool wasVisited;   //檢查是否被訪問過
    char Label;
};

class Graph
{
public:
    Graph();   //建構陣列
    ~Graph();  //刪除
    void addVertex(char lab); //新增節點
    void addEdge(int Start,int End);  //新增邊
    void PrintMatrix(); //列印矩陣
    void showVertex(int v); //秀節點
    void BFS();  //廣度優先搜尋
private:
    Vertex* vertexList[10]; //最多頂點的數量
    int nVerts;     //實際陣列頂點的數量
    int adjMat[10][10];  //矩陣
    int getAdjUnvisitedVertex(int v);
    string AZ[10];
};
void Graph::BFS()//廣度優先搜尋
{
  queue<int> gQueue;
  vertexList[0]->wasVisited=true;
  showVertex(0);//秀找到的節點
  gQueue.push(0);//push節點
  int Vert1,Vert2;
  while(gQueue.size()>0)
  {
      Vert1=gQueue.front();//
      gQueue.pop();
      Vert2=getAdjUnvisitedVertex(Vert1);//取得下一節點
      while(Vert2!=-1)//代表有找到下一節點，並且沒有訪問過的
      {
          vertexList[Vert2]->wasVisited=true;//下一節點宣告訪問過了
          showVertex(Vert2);//秀找到的節點
          gQueue.push(Vert2);//push節點
          Vert2=getAdjUnvisitedVertex(Vert1);//重複尋找下一節點直到結束
      }
  }
  cout<<endl;
  for(int i=0;i<nVerts;i++)
    vertexList[i]->wasVisited=false;
}

int Graph::getAdjUnvisitedVertex(int v)  //尋找要訪問下一個
{
   for(int j=0;j<nVerts;j++)
   {
       if((adjMat[v][j]==1)&&(vertexList[j]->wasVisited==false))  //檢視是否鄰接的而且未被訪問過的
       return j;
   }
   return -1;
}

void Graph::showVertex(int v)
{
    cout<<vertexList[v]->Label<<" ";
}
Graph::Graph()  //建構函式
{
  nVerts=0;
  for(int i=0;i<10;i++)
        for(int j=0;j<10;j++)
          adjMat[i][j]=0;   //全部初始化為0
}


void Graph::addVertex(char lab)//放入節點名稱
{  AZ[nVerts]=lab;
   vertexList[nVerts++]=new Vertex(lab);

}

void Graph::addEdge(int Start,int End) //增加一條邊
{
  adjMat[Start][End]=1; //有相連則在陣列中變為1
  adjMat[End][Start]=1; //有相連則在陣列中變為1
}

void Graph::PrintMatrix()
{
    cout<<"每點連接陣列:"<<endl<<"   ";
  for(int j=0;j<nVerts;j++)
   {
        cout<<AZ[j]<<" ";
   }
   cout<<endl;
  for(int i=0;i<nVerts;i++)
  {cout<<AZ[i]<<" :";
      for(int j=0;j<nVerts;j++)
      {
        cout<<adjMat[i][j]<<" ";
      }
      cout<<endl;
  }
}
Graph::~Graph()//刪除節點
{
    for(int i=0;i<nVerts;i++)
        delete vertexList[i];
}
int main()
{
    Graph g;
    g.addVertex('A');
    g.addVertex('B');
    g.addVertex('C');
    g.addVertex('D');
    g.addVertex('E');
    g.addVertex('F');


    g.addEdge(0,1);  //A-B
    g.addEdge(0,3);  //A-D
    g.addEdge(1,0);  //B-A
    g.addEdge(1,4);  //B-E
    g.addEdge(2,4);  //C-E
    g.addEdge(3,0);  //D-A
    g.addEdge(3,4);  //D-E
    g.addEdge(4,1);  //E-B
    g.addEdge(4,2);  //E-C
    g.addEdge(4,3);  //E-D
    g.addEdge(4,5);  //E-F

    g.PrintMatrix();
    cout << "BFS:" << endl;
    g.BFS();
    return 0;
}
