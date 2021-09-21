package tp3;

import tp1.MySet;
import java.util.Collections;

public class MySortedSet extends MySet {
    public MySortedSet() {
        super();
    }

    public MySortedSet(MySortedSet ms) {
        super(ms);
    }

    public void add(double e) {
        if (!this.data.contains(e)) {
            this.data.add(e);
            Collections.sort(this.data);
        }
    }

    public double get(int i) {
        assert (!(this.isEmpty())): "WARNING EMPTY STACK";
        assert (i >= 0): "i trop petit";
        assert (i < this.data.size()): "i trop grand";
        return this.data.get(i);

    }

    public MySortedSet difference(MySortedSet m2) {
        MySortedSet m = new MySortedSet();
        m = this.union(m2);
        for (int i = 0; i < m2.size(); i++) {
            if (this.contains(m2.get(i))) {
                m.data.remove(m2.get(i));
            }
        }
        return m;
    }

    public boolean subset(MySortedSet m2) {
        int rep = 0;
        if (this.size() < m2.size())
            return false;
        for (int i = 0; i < m2.size(); i++) {
            if (!this.contains(m2.get(i)))
                rep++;
        }
        return rep == 0;
    }


    public MySortedSet intersection(MySortedSet m2) {
        MySortedSet m = new MySortedSet();
        for (int i = 0; i < m2.size(); i++) {
            if (this.contains(m2.get(i)))
                m.add(m2.get(i));
        }
        return m;
    }

    public MySortedSet union(MySortedSet m) {
        MySortedSet temp = new MySortedSet();
        for (int i = 0; i < this.size() ; i++) {
            temp.data.add(this.get(i));
        }
        for (int i = 0; i < m.size() ; i++) {
            if (!temp.contains(m.get(i)))
                temp.data.add(m.get(i));
        }
        Collections.sort(temp.data);
        return temp;

    }

    public double nearest(double val) {
        assert (!this.isEmpty()) :"WARNING EMPTY STACK";
        if (this.contains(val)) {
            return val;
        }
        if (val < this.get(0)) {
            return this.get(0);
        }
        if (val > this.get(this.size() - 1)) {
            return this.get(this.size() -1);
        }

        double nearest = 0;
        int mid = (this.size() + this.size()%2)/2;
        int ecart = (mid + mid%2)/2;
        while (!(this.get(mid ) < val && this.get(mid + 1) > val)) {
            if (this.get(mid) < val)
                mid = mid + ecart;
            else
                mid = mid - ecart ;
            ecart = (ecart + ecart%2) /2;
        }
        if ((val - this.get(mid)) < (this.get(mid + 1) - val)) {
            nearest = this.get(mid);
        } else {
            nearest =  this.get(mid + 1);
        }
        return nearest;
    }
}
