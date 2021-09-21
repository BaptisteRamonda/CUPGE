package tp3;

import java.awt.Point;
import java.awt.Color;

public class Rectangle{
    /*
    Constructor
    */
    protected Point topLeft;
    protected Point botRight;

    protected Rectangle(Point p1, Point p2){
        this.topLeft = new Point(p1);
        this.botRight = new Point(p2);
    }

    /*
    Methods
     */
    //Translate the rectangle
    public void translate(int x, int y){
        this.topLeft.translate(x,y);
        this.botRight.translate(x,y);
    }

    //Return the left top of the rectangle
    public Point getTopLeft(){
        return this.topLeft;
    }

    //Return the right bot of the rectangle
    public Point getBotRight(){
        return this.botRight;
    }

    //Describe the rectangle ; return a string
    public String toString(){
        return "(" + this.topLeft.toString() + ", " + this.botRight.toString() + ")";
    }

    //Verify th equality between two rectangles
    public boolean equals(Object o){
        if (o == null)
            return false;
        if (!(o instanceof Rectangle))
            return false;
        Rectangle r = (Rectangle) o;
        return this.topLeft.equals(r.topLeft) && this.botRight.equals(r.botRight);
    }
}
