package Graph;

import java.util.*;

public class Arch<T,G> {
    T start;
    T end;
    G weight;

    public Arch(T end, G weight) {
        this.start = start;
        this.end = end;
        this.weight = weight;
    }


    public T getStart() {
        return start;
    }

    public void setStart(T start) {
        this.start = start;
    }

    public T getEnd() {
        return end;
    }

    public void setEnd(T end) {
        this.end = end;
    }

    public G getWeight() {
        return weight;
    }

    public void setWeight(G weight) {
        this.weight = weight;
    }

    public static <G extends Number> int compare(G x,G y) throws Exception {
        if(x == null && y == null) throw new Exception("Two number are null!");
        if(x == null) {
            return -1;
        }
        if(y instanceof Integer)
            if(x.intValue() - y.intValue() < 0)
                return -1;
            else if(x.intValue() - y.intValue() > 0)
                return 1;
            else
                return 0;
        if(y instanceof Double)
            if(x.doubleValue() - y.doubleValue() < 0)
                return -1;
            else if(x.doubleValue() - y.doubleValue() > 0)
                return 1;
            else
                return 0;
        if(y instanceof Float)
            if(x.floatValue() - y.floatValue() < 0)
                return -1;
            else if(x.floatValue() - y.floatValue() > 0)
                return 1;
            else
                return 0;

        throw new Exception("Bad input!");
    }

    public static <G extends Number> G add(G x,G y) throws Exception {
        if(x == null || y == null)  return null;
        if(x == null) {
            if(y instanceof Integer)
                return (G) Integer.valueOf(y.intValue());
            if(y instanceof Double)
                return (G) Double.valueOf(y.doubleValue());
            if(y instanceof Float)
                return (G) Float.valueOf(y.floatValue());
        } else {
            if(y instanceof Integer)
                return (G) Integer.valueOf(x.intValue() + y.intValue());
            if(y instanceof Double)
                return (G) Double.valueOf(x.doubleValue() + y.doubleValue());
            if(y instanceof Float)
                return (G) Float.valueOf(x.floatValue() + y.floatValue());
        }
        throw new Exception("Illegal Arguments");
    }

    @Override
    public boolean equals(Object o) {
        if (this == o)
            return true;
        if (o == null || getClass() != o.getClass())
            return false;

        Arch<?, ?> arch = (Arch<?, ?>) o;
        return Objects.equals(end, arch.end);
    }

    @Override
    public int hashCode() {
        return Objects.hash(end,weight);
    }

    @Override
    public String toString() {
        return "start: " + start + "\t end: " + end + "\t weight:" + weight;
    }



}
