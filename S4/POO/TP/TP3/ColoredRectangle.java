package tp3;

import javax.swing.*;
import java.awt.*;

public class ColoredRectangle extends Rectangle implements Comparable{

    /*
    Constructor
     */

    protected Color color;
    protected ColoredRectangle(Point p1, Point p2, Color c) {
        super(p1, p2);
        this.color = c;
    }

    /*
    Methods
     */

    public int compareTo(Object o) {
        float a1, a2;
        ColoredRectangle r = (ColoredRectangle) o;
        a1 = (this.topLeft.y - this.botRight.y) * (this.botRight.x - this.topLeft.x);
        a2 = (topLeft.y - r.botRight.y) * (r.botRight.x - r.topLeft.x);
        if (a1 == a2)
            return 0;
        if (a1 > a2)
            return 1;
        else
            return -1;
    }
}
