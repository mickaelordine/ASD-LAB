package Dijkstra;

import Graph.*;

import java.io.BufferedReader;
import java.io.IOException;
import java.nio.charset.Charset;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class Main {
    public static String start = "torino";
    public static String end = "catania";
    private static String filepath = "italian_dist_graph.csv";
    private static final Charset ENCODING = StandardCharsets.UTF_8;

    public static void main(String[] args) {
        Graph<String,Float> graph = new Graph<String, Float>(false);
        Path inputFilePath = Paths.get(filepath);
        Map<String,Float> result;

        System.out.println("Loading data from file...");

        try (BufferedReader fileinputrReader = Files.newBufferedReader(inputFilePath, ENCODING)) {
            String line = null;

            while ((line = fileinputrReader.readLine()) != null) {
                String[] lineElements = line.split(",");

                graph.add_arch(lineElements[0], lineElements[1], Float.parseFloat(lineElements[2]));
            }

        } catch (Exception e) {
            e.printStackTrace();
        }
        System.out.println("DONE\n");

        System.out.println("Graph generated:\n");

        try {

            System.out.println("Applying Dijkstra ... ");

            result = new Dijkstra<String, Float>().Dijkstra(graph, new FloatComp(), (float) 0, Float.POSITIVE_INFINITY);

            System.out.println("Number of arches found: " + result.size() + "\n" + result.get(end)/(float)1000 + " km");

        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
