package tp4;

public class FileChaineeGen<E> implements IFileGen<E>{

    /*
    ATTRIBUTES
     */
    protected int size;
    protected Cellule head;
    protected Cellule tail;

    /*
    INNER CLASS
     */
    protected class Cellule{
        //attributes
        protected Cellule next;
        protected  E value;
        //constructor
        protected Cellule(E e){
            this.next = null;
            this.value = e;
        }
    }

    /*
    CONSTRUCTOR
    */
    public FileChaineeGen(){
        this.size = 0;
        this.head = null;
        this.tail = null;
    }

    /*
    METHODS
     */

    public boolean add(E o) {
        Cellule cell = new Cellule(o);
        if (this.size == 0) {
            this.tail = cell;
            this.head = cell;
        } else {
            this.tail.next = cell;
            this.tail = cell;
        }
        this.size ++;
        return true;
    }

    public boolean remove() {
        assert (this.size > 0) : "WARNING : FILE VIDE.";
        if (this.size == 1){
            this.head = null;
            this.tail = null;
            this.size = 0;
        }
        else{
            this.head = this.head.next;
            this.size --;
        }
        return true;
    }

    public boolean isEmpty() { return this.size == 0; }

    public int size() { return this.size; }

    public E get() {
        assert (!this.isEmpty()) : "WARNING : FILE VIDE";
        return this.head.value;
    }

    public String toString() {
        if (this.isEmpty()) {
            return "[]";
        }
        StringBuilder message = new StringBuilder("[");
        Cellule actualCell = this.head;
        message.append(actualCell.value);
        for (int i = 1; i < this.size(); i++) {
            message.append(", ").append(actualCell.value);
            actualCell = actualCell.next;
        }
        return message + "]";
    }

    public boolean equals(Object o) {
        boolean count = true;
        if (o == null) {
            return false;
        }
        if (!(o instanceof FileChaineeGen)) {
            return false;
        }
        FileChaineeGen<E> f = (FileChaineeGen<E>) o;
        if (this.size() != f.size()) {
            return false;
        }
        Cellule actualValue = this.head;
        Cellule actualFValue = f.head;
        for (int i = 0; i < this.size(); i++) {
            if (!(actualValue.value.equals(actualFValue.value))) {
                count = false;
            }
            actualValue = actualValue.next;
            actualFValue = actualFValue.next;
        }
        return count;
    }
}
