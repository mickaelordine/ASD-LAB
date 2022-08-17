package Dijkstra;

import MinHeap.*;
import Graph.*;

import java.util.Comparator;
import java.util.*;
import java.util.stream.Collectors;


public class Dijkstra<T,G extends Number> {
    private T start = (T) Main.start;
    private T end = (T) Main.end;

    public Map<T, G> Dijkstra(Graph<T, G> g, Comparator<Arch<T,G>> comparator, G startValue, G INF) throws Exception{
        MinHeap<Arch<T,G>> minHeap = new MinHeap<Arch<T, G>>(new FloatCompare());
        HashMap<T,G> map = new HashMap<>(); //contiene la città start e tutti gli end
        Arch<T,G> tempArch;


        for(T t : g.get_vertexes()){
            if(t.equals(start)){
                minHeap.insert(new Arch<T, G>(t,startValue));
                map.put(t,startValue);
            }else{
                minHeap.insert(new Arch<T, G>(t,INF));
                map.put(t,INF);
            }
        }


        while(!minHeap.isEmpty()){
            tempArch = minHeap.extractMin();
            for(Arch<T,G> arch : g.getAdjacentVertex(tempArch.getEnd())){
                //dist[v] > dist[u] + dist(u+v) u-> temporaneo, v-> peso per la end
                // V->vertex getAdjacentVertex
                // U->MinHeap removed
                //contains verifico che cò che ho rimosso esiste in MAP
                if(minHeap.contains(new Arch<>(arch.getEnd(),map.get(arch.getEnd()))) &&
                        Arch.compare(map.get(arch.getEnd()),Arch.add(g.getEdgeLabel(tempArch.getEnd(),arch.getEnd()),tempArch.getWeight()))>0){
                    minHeap.decreaseKey(new Arch<T, G>(arch.getEnd(),map.get(arch.getEnd())),new Arch<T, G>(arch.getEnd(),Arch.add(g.getEdgeLabel(tempArch.getEnd(),arch.getEnd()),tempArch.getWeight())));
                    map.replace(arch.getEnd(),Arch.add(g.getEdgeLabel(tempArch.getEnd(),arch.getEnd()),tempArch.getWeight())); //aggiorno il valore nella mappa
                }
            }
        }
        return map;
    }


}

