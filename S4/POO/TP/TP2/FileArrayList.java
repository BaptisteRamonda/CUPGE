package tp2;

import java.util.ArrayList;

public class FileArrayList implements IFile {
    protected ArrayList<Double> data;
    /*
    Constructor
     */
    public FileArrayList() {this.data = new ArrayList<>();}

    /*
    Methods
     */

    public boolean add(double e) {
        assert (!this.data.contains(e)): "Warning, element e is already present in queue";
        this.data.add(e);
        return true;
    }

    public boolean remove() {
        assert (this.data.size()>0): "Warning empty queue";
        this.data.remove(0);
        return true;
    }

    public boolean isEmpty() {return this.data.size() == 0;}

    public int size() {return this.data.size();}

    public double get() {
        assert (this.data.size() > 0): "Warning empty queue";
        return this.data.get(0);
    }

    public boolean equals(Object o) {
        if (!(o instanceof FileArrayList)) {
            return false;
        }
        FileArrayList g = (FileArrayList) o;
        if (this.size() == g.size()) {
            return (this.data.containsAll(g.data));
        }
        return false;
    }

    public String toString(){return this.data.toString();}

}
