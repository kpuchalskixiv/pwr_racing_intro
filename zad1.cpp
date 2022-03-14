#include "zad1.h"
using namespace std;


vector<vector<pair<int, int>>> magazyn;
              // vertex, vertex,
              //cost (*10 to work on ints only),
              //color green 0 yellow 1 red 2
// A - wierzcholek 0, B - wierzcholek 13
void set_up(){

    colors=(int *)malloc(3*sizeof(int));
    printf("Enter green, yellow and red costs (in that order) as intenegers\n");
    scanf("%d %d %d", &colors[0], &colors[1], &colors[2]);

    FILE *magazyntxt;
    magazyntxt=fopen("magazyn.txt", "r");

    magazyn.resize(14); //14 vertexes in graph
    //read hardcoded file into vector
    int a,b,c,d;
    for(int i=0; i<18; i++){ // wc -l magazyn.txt->18
        fscanf(magazyntxt , "%d %d %d %d", &a,&b,&c,&d);
        magazyn[a].push_back(make_pair(b,c*colors[d]));
        magazyn[b].push_back(make_pair(a,c*colors[d]));
    }
    fclose(magazyntxt);
    free(colors);

}

int search(){
  priority_queue<pair<int, int> > Que;
  dist=(int *)malloc(14*sizeof(int));

  for(int v=1; v<14; v++){
      dist[v]=INT_MAX;
  }
  dist[0]=0;
  Que.push(make_pair(-dist[0], 0));

  int u,d,s;
  int next_v, next_d;
  while(!Que.empty()){
      u=Que.top().second;
      d=-Que.top().first;
      Que.pop();

      s=magazyn[u].size();
      for(int v=0; v<s; v++){
          next_v=magazyn[u][v].first;
          next_d=magazyn[u][v].second;
          if(dist[next_v]>dist[u]+next_d){
              dist[next_v]=dist[u]+next_d;
              if(next_v==13){ //found B
                  return 0;
              }
              Que.push(make_pair(-dist[next_v], next_v));
          }
      }
  }
  return -1;
}

int main()
{
    set_up();

    if(search()!=-1)
        printf("\nMinimal cost of getting from A to B is %.2f\n", ((double)dist[13])/10.0);
    else
        printf("Path not found\n");

    free(dist);

    return 0;
}
