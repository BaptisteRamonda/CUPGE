package tp1;

import java.util.ArrayList;

public class MySet {
    protected ArrayList<Double> data;
    /*
    Constructor
     */
    public MySet() {
        this.data = new ArrayList<>();
    }
    public MySet(MySet m){
        this.data = new ArrayList<>();
        int i;
        for (i =0; i < m.data.size(); i++ ){
            this.data.add(m.data.get(i));
        }
    }

    /*
    Methods
     */

    public void add(double e){
        if (!this.data.contains(e))
            this.data.add(e);
    }

    public int size(){
        return this.data.size();
    }

    public boolean isEmpty(){
        return this.data.size() == 0;
    }

    public boolean remove(double e) {
        return this.data.remove(e);
    }

    public boolean contains(double e) {
        return this.data.contains(e);
    }

    public void clear() {
        this.data.clear();
    }

    public String toString() {
        return this.data.toString();
    }

    public int getRandomInt(int max) {
        return (int)Math.floor(Math.random() * Math.floor(max));
    }

    public Double random() {
        assert !this.isEmpty() : "pile vide";
        return this.data.get(this.getRandomInt(this.data.size()));
    }

    public boolean equals(MySet test) {
        if (test == null)
            return false;
        if (this.data.size() != test.data.size()) {
            return false;
        } else {
            int count = 0;
            for(int i = 0; i < this.data.size(); i++) {
                if (this.data.contains(test.data.get(i)))
                    ++count;
            }
            return count >= this.data.size();
        }
    }
}
