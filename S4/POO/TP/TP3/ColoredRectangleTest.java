package tp3;

import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertFalse;
import static org.junit.Assert.assertTrue;

import java.awt.*;

import org.junit.After;
import org.junit.Before;
import org.junit.Test;

public class ColoredRectangleTest {
    ColoredRectangle r1;
    ColoredRectangle r2;
    ColoredRectangle r3;

    @Before
    public void setUp() throws Exception {
        r1 = new ColoredRectangle(new Point(0, 1), new Point(1, 0), Color.blue);
        r2 = new ColoredRectangle(new Point(0, 1), new Point(1, 0), Color.white);
        r3 = new ColoredRectangle(new Point(5, 10), new Point(10, 5), Color.red);
    }

    @After
    public void tearDown() throws Exception {
        r1 = null;
        r2 = null;
        r3 = null;
        System.gc();
    }

    @Test
    public void compareTo() {
        assertEquals(0, r1.compareTo(r2));
        assertEquals(1, r3.compareTo(r1));
    }
}
