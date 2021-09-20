package tp1;

public class MaPileEntiers implements IPileEntiers{
    private int size;
    private final int[] stack;

    /**
     Constructor
     */

    public MaPileEntiers(int sizeMax) {
        this.stack = new int[sizeMax];
        this.size = 0;
    }

    /**
     Methods
     */

    public boolean add(int val) {
        if (this.size < this.stack.length) {
            this.stack[this.size] = val;
            this.size ++;
            return true;
        } else {
            return false;
        }
    }

    public boolean remove() {
        if (this.size > 0) {
            this.size --;
            return true;
        } else {
            return false;
        }
    }

    public int get() {
        assert this.size > 0 : "Empty Stack, can't run get()";
        return this.stack[this.size - 1];
    }

    public int size() {
        return this.size;
    }

    public int capacity() {
        return this.stack.length;
    }

    public boolean isFull() {
        return this.size == this.stack.length;
    }

    public boolean isEmpty() {
        return this.size == 0;
    }

    public String toString() {
        StringBuilder message = new StringBuilder("[");
        if (this.size >= 1) {
            message.append(this.stack[0]);
        }
        for (int i = 1; i < this.size; i ++) {
            message.append(", ").append(this.stack[i]);
        }
        message.append("]");
        return message.toString();
    }

    public boolean equals(MaPileEntiers test) {
        if (this.size != test.size) {
            return false;
        } else {
            int count = 0;

            for(int i = 0; i < this.size; ++i) {
                if (this.stack[i] == test.stack[i]) {
                    ++count;
                }
            }
            return count >= this.size;
        }
    }

}
