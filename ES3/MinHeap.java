import java.util.ArrayList;
import java.util.Comparator;
import java.util.HashMap;
import java.util.Map;


public class MinHeap<T>{


    private Map<T,Integer> map;
    private Comparator compare;
    private ArrayList<T> list;

    public MinHeap(Comparator comparator) {
        this.map= new HashMap<>();
        this.compare = comparator;
        this.list = new ArrayList<T>();
    }

    public int getSize(){ //restituzione della dimensione dello heap - O(1);
        return list.size();
    }

    public void insert(T item) {
        list.add(item);
        map.put(item,list.size()-1); //qui creo key,pos
        int i = list.size() - 1;
        int parent = parent(i);

        while (parent != i && compare.compare(list.get(i),list.get(parent)) < 0) {
            swap(i, parent);
            i = parent;
            parent = parent(i);
        }
    }


    public T extractMin() { //estrazione dell'elemento con valore minimo - O(log n);

        if (list.size() == 0) {

            throw new IllegalStateException("MinHeap is EMPTY");
        } else if (list.size() == 1) {

            T min = list.remove(0);
            return min;
        }

        // remove the last item ,and set it as new root
        T min = list.get(0);
        T lastItem = list.remove(list.size() - 1);
        list.set(0, lastItem);
        map.replace(list.get(0),0); //primo item come primo item

        // bubble-down until heap property is maintained
        minHeapify(0);

        // return min key
        return min;
    }

    public int getPosition(T item){
        return map.get(item);
    }

    public void decreaseKey(T item,T dcr) throws Exception{ //diminuzione del valore di un elemento - O(log n).
        if(compare.compare(item,dcr)<0) throw new Exception("Previous item was smaller than this!");
        int size = getPosition(item);
        list.set(size,dcr);
        map.replace(dcr,size);
        while(size > 0 && compare.compare(list.get(parent(size)),list.get(size)) > 0) {
            swap(size,parent(size));
            size = parent(size);
        }
    }

    public boolean contains(T o){
        return map.containsKey(o);
    }

    private void minHeapify(int i) { //O(log n)

        int left = left(i);
        int right = right(i);
        int smallest;

        // find the smallest key between current node and its children.
        if (left <= list.size() - 1 && compare.compare(list.get(left),list.get(i)) < 0) {
            smallest = left;
        } else {
            smallest = i;
        }

        if (right <= list.size() - 1 && compare.compare(list.get(right),list.get(smallest)) <0) {
            smallest = right;
        }

        // if the smallest key is not the current key then bubble-down it.
        if (smallest != i) {

            swap(i, smallest);
            minHeapify(smallest);
        }
    }

    public int getMin() {
        return (Integer) list.get(0);
    }

    public boolean isEmpty() {
        return list.size() == 0;
    }

    private int right(int i) { //restituzione del figlio destro di un elemento - O(1);

        return 2 * i + 2;
    }

    private int left(int i) { //restituzione del figlio sinistro di un elemento - O(1);

        return 2 * i + 1;
    }

    private int parent(int i) { //restituzione del genitore di un elemento - O(1);

        if (i % 2 == 1) {
            return i / 2;
        }

        return (i - 1) / 2;
    }

    private void swap(int i, int parent) {
        map.replace(list.get(i),parent);
        map.replace(list.get(parent),i);
        T temp = list.get(parent);
        list.set(parent, list.get(i));
        list.set(i, temp);
    }

    public Integer IntegerCompare(T list1, T list2){
        return (Integer) list1 - (Integer) list2;
    }

    public Double DoubleCompare(T list1, T list2){
        return (Double) list1 - (Double) list2;
    }

    @Override
    public String toString(){
        String result = "";
        for (int i=0; i< list.size(); i++ ){
            result = result + list.get(i) + "\n";
        }
        return result;
    }

}