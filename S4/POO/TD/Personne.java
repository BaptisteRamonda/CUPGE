package exercicesTD;

import java.util.GregorianCalendar;
import java.util.Scanner;

public class Personne implements Comparable<Personne>{
    /** Name */
    protected String nom;
    /** Birth Date */
    protected GregorianCalendar date;

    public Personne(String nm, int j, int m, int a) {
        nom = nm;
        setDate(j, m, a);
    }

    private void setDate(int j, int m, int a) throws IllegalArgumentException {
        if (a <= 1900)
            throw new IllegalArgumentException("DATE ERROR");
        if (m < 1 || m > 12 )
            throw new IllegalArgumentException("MONTH ERROR");
        if (j < 1 || j > nbJours(a, m))
            throw new IllegalArgumentException("DAY ERROR");
        date = new GregorianCalendar(a, m ,j);
    }

    private int nbJours(int a, int m) throws IllegalArgumentException {
        if ( m == 2){
            if (date.isLeapYear(a)){
                return 29;
            }
            return 28;
        }
        if ( m == 4 || m == 6 || m == 9 || m == 11 ){
            return 30;
        }
        return 31;
    }

    public int compareTo(Personne o) {
        if (this.date.equals(o.date))
            return 0;
        if (this.date.before(o.date)){
            return 1;
        }
        return -1;
    }

    public boolean equals(Object o) {
        if (o == null)
            return false;
        if (!o.getClass().equals(this.getClass()))
            return false;
        Personne p = (Personne) o;
        return (date.equals(p.date));
    }

    public String toString(){
        return "[" + nom + " " + date.getTime() + "]";
    }

}
