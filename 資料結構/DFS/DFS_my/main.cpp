 #include "../00_Libs/nsInclude.h"
 #include "../00_Libs/nsQueue.h"
 #include "../00_Libs/nsGraph.h"

 enum COLOR {
 WHITE=0, GRAY=1, BLACK=2
 };

int main()
 {

 MyGraph g("../GraphDef-001.txt");
 /* BFS */
 int n = g.sizeV();
 MyGraph DK(n, true);
 MyQueue<int> q;


 g.show();
 return 0;
 }
