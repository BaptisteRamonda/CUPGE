package tp1;

public interface IPileEntiers {
    /**
     * Ajoute une valeur au sommet de la pile
     * prend en param val la valeur à empiler
     * return true si ok, false sinon
     */
    public boolean add(int val);

    /**
     * Enlève (logiquement) la valeur en sommet de la pile
     * return true si ok, false sinon
     */
    public boolean remove();

    /**
     * Retourne la valeur au sommet de la pile. Renvoie un assert si la pile est
     * vide
     */
    public int get();

    /**
     * retourne la taille de la pile
     */
    public int size();

    /**
     * retourne la capacité de la pile (taille max)
     */
    public int capacity();

    /**
     * indique si la pile est pleine
     * return true si pleine, false sinon
     */
    public boolean isFull();

    /**
     * indique si la pile est vide
     * return true si ok, false sinon
     */
    public boolean isEmpty();
}
