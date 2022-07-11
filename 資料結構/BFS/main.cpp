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
    bool wasVisited;   //�ˬd�O�_�Q�X�ݹL
    char Label;
};

class Graph
{
public:
    Graph();   //�غc�}�C
    ~Graph();  //�R��
    void addVertex(char lab); //�s�W�`�I
    void addEdge(int Start,int End);  //�s�W��
    void PrintMatrix(); //�C�L�x�}
    void showVertex(int v); //�q�`�I
    void BFS();  //�s���u���j�M
private:
    Vertex* vertexList[10]; //�̦h���I���ƶq
    int nVerts;     //��ڰ}�C���I���ƶq
    int adjMat[10][10];  //�x�}
    int getAdjUnvisitedVertex(int v);
    string AZ[10];
};
void Graph::BFS()//�s���u���j�M
{
  queue<int> gQueue;
  vertexList[0]->wasVisited=true;
  showVertex(0);//�q��쪺�`�I
  gQueue.push(0);//push�`�I
  int Vert1,Vert2;
  while(gQueue.size()>0)
  {
      Vert1=gQueue.front();//
      gQueue.pop();
      Vert2=getAdjUnvisitedVertex(Vert1);//���o�U�@�`�I
      while(Vert2!=-1)//�N�����U�@�`�I�A�åB�S���X�ݹL��
      {
          vertexList[Vert2]->wasVisited=true;//�U�@�`�I�ŧi�X�ݹL�F
          showVertex(Vert2);//�q��쪺�`�I
          gQueue.push(Vert2);//push�`�I
          Vert2=getAdjUnvisitedVertex(Vert1);//���ƴM��U�@�`�I���쵲��
      }
  }
  cout<<endl;
  for(int i=0;i<nVerts;i++)
    vertexList[i]->wasVisited=false;
}

int Graph::getAdjUnvisitedVertex(int v)  //�M��n�X�ݤU�@��
{
   for(int j=0;j<nVerts;j++)
   {
       if((adjMat[v][j]==1)&&(vertexList[j]->wasVisited==false))  //�˵��O�_�F�����ӥB���Q�X�ݹL��
       return j;
   }
   return -1;
}

void Graph::showVertex(int v)
{
    cout<<vertexList[v]->Label<<" ";
}
Graph::Graph()  //�غc�禡
{
  nVerts=0;
  for(int i=0;i<10;i++)
        for(int j=0;j<10;j++)
          adjMat[i][j]=0;   //������l�Ƭ�0
}


void Graph::addVertex(char lab)//��J�`�I�W��
{  AZ[nVerts]=lab;
   vertexList[nVerts++]=new Vertex(lab);

}

void Graph::addEdge(int Start,int End) //�W�[�@����
{
  adjMat[Start][End]=1; //���۳s�h�b�}�C���ܬ�1
  adjMat[End][Start]=1; //���۳s�h�b�}�C���ܬ�1
}

void Graph::PrintMatrix()
{
    cout<<"�C�I�s���}�C:"<<endl<<"   ";
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
Graph::~Graph()//�R���`�I
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
