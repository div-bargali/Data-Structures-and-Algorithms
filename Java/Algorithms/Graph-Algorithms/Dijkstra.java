import java.util.*;
import java.lang.*;
class DijkstraAlgo{
    static final int V=9;
    static int minDistance(int dist[], Boolean sptset[]){
        int min=Integer.MAX_VALUE, min_index=-1;
        for(int v=0;v<V;v++){
            if(sptset[v]==false && dist[v]<=min){
                min=dist[v];
                min_index=v;
            }
        }
        return min_index;
    }
    static void printSolution(int dist[]){
        System.out.println("Vertex \t\t Distance from Source");
        for(int v=0;v<V;v++)
            System.out.println(v+"\t\t"+dist[v]);
    }
    static void dijkstra(int graph[][], int src){
        int dist[]=new int[V];
        Boolean sptset[]=new Boolean[V];

        dist[src]=0;
        sptset[src]=false;
        for(int v=1;v<V;v++){
            dist[v]=Integer.MAX_VALUE;
            sptset[v]=false;
        }
        for(int count=0;count<V-1;count++){
            int u=minDistance(dist,sptset);
            sptset[u]=true;
            for(int v=0;v<V;v++){
                if(sptset[v]==false && graph[u][v]!=0 && dist[u]!= Integer.MAX_VALUE && 
                        (dist[u]+ graph[u][v]) < dist[v]
                    )
                    dist[v]=dist[u]+graph[u][v];
            }   
        }
        printSolution(dist);
    }
    public static void main(String[] args) {
        int graph[][]=new int[][]{ 
                { 0, 4, 0, 0, 0, 0, 0, 8, 0 }, 
                { 4, 0, 8, 0, 0, 0, 0, 11, 0 }, 
                { 0, 8, 0, 7, 0, 4, 0, 0, 2 }, 
                { 0, 0, 7, 0, 9, 14, 0, 0, 0 }, 
                { 0, 0, 0, 9, 0, 10, 0, 0, 0 }, 
                { 0, 0, 4, 14, 10, 0, 2, 0, 0 }, 
                { 0, 0, 0, 0, 0, 2, 0, 1, 6 }, 
                { 8, 11, 0, 0, 0, 0, 1, 0, 7 }, 
                { 0, 0, 2, 0, 0, 0, 6, 7, 0 } }; 
        dijkstra(graph, 0);
        
    }
}