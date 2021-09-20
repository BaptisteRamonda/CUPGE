package tp1;

import org.junit.jupiter.api.AfterEach;
import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;
import static junit.framework.Assert.assertEquals;

class MySetTest {
    private MySet m1;
    private MySet m2;
    private MySet m3;

    @BeforeEach
    void setUp() throws Exception {
        m1 = new MySet();
        m2 = new MySet();
        m3 = new MySet();
    }

    @AfterEach
    void tearDown() throws Exception {
        m1 = null;
        m2 = null;
        m3 = null;
    }

    @Test
    void testMySet() {
        Assertions.assertEquals(0, m1.size(), "error constructor");
    }

    @Test
    void testMySetMySet() {
        Assertions.assertEquals(0, m2.size(), "error of constructor by copy of an empty field");
        m1.add(1.0);
        m2 = new MySet(m1);
        Assertions.assertEquals(1, m2.size(), "error of constructor by copy");
        Assertions.assertTrue(m2.contains(1.0), "error of constructor by copy");
    }

    @Test
    void testClear() {
        m1.clear();
        Assertions.assertEquals(0, m1.size(), "error clear ensemble vide");
        m1.add(12.0);
        m1.add(8.0);
        m1.add(3.0);
        m1.add(10.0);
        m1.clear();
        Assertions.assertEquals(0, m1.size(), "error clear ensemble non vide");
    }

    @Test
    void testSize() {
        Assertions.assertEquals(0, m1.size(), "error size ensemble vide");
        m1.add(12.0);
        Assertions.assertEquals(1, m1.size(), "error size");
        m1.add(12.0);
        Assertions.assertEquals(1, m1.size(), "error size");
        m1.add(3.0);
        m1.add(10.0);
        Assertions.assertEquals(3, m1.size(), "error size");
    }

    @Test
    void testIsEmpty() {
        Assertions.assertTrue(m1.isEmpty(), "error isEmpty ensemble vide");
        m1.add(1.0);
        Assertions.assertFalse(m1.isEmpty(), "error isEmpty");
        m1.add(1.0);
        Assertions.assertFalse(m1.isEmpty(), "error isEmpty");
    }

    @Test
    void testAdd() {
        m1.add(1.0);
        Assertions.assertTrue(m1.contains(1.0), "error add");
        Assertions.assertFalse(m1.contains(0.0), "error add");
        m1.add(1.0);
        Assertions.assertEquals(1, m1.size(), "error add");
        m1.add(10.0);
        Assertions.assertEquals(2, m1.size(), "error add");
        m1.add(10.0);
        Assertions.assertEquals(2, m1.size(), "error add");
        m1.add(15.0);
        m1.add(15.0);
        Assertions.assertEquals(3, m1.size(), "error add");
        m1.add(12.0);
        m1.add(8.0);
        m1.add(3.0);
        m1.add(10.0);
        Assertions.assertEquals(6, m1.size(), "error add");
    }

    @Test
    void testRemove() {
        Assertions.assertFalse(m1.remove(0.0), "error remove ensemble vide");
        m1.add(1.0);
        m1.add(2.0);
        Assertions.assertTrue(m1.remove(1.0), "error remove");
        Assertions.assertEquals(1, m1.size(), "error remove");
        Assertions.assertFalse(m1.remove(3.0), "error remove");
        Assertions.assertEquals(1, m1.size(), "error remove");
    }

    @Test
    void testContains() {
        Assertions.assertFalse(m1.contains(0.0), "error contains ensemble vide");
        m1.add(1.0);
        m1.add(2.0);
        Assertions.assertTrue(m1.contains(1.0), "error contains");
        Assertions.assertFalse(m1.contains(3.0), "error contains");
    }

    @Test
    void testRandom() {
        double v;
        try {
            v = m1.random();
            Assertions.fail("assertion no return back, ensemble vide");
        } catch (AssertionError ae) {
            assert (true);
        }
        m1.add(1.0);
        m1.add(15.0);
        m1.add(15.0);
        m1.add(12.0);
        m1.add(8.0);
        m1.add(8.0);
        m1.add(3.0);
        m1.add(10.0);
        v = m1.random();
        Assertions.assertTrue(m1.contains(v), "error random");

    }

    @Test
    void testToString() {
        Assertions.assertEquals("[]", m1.toString(), "error toString, ensemble vide");
        m1.add(1.0);
        Assertions.assertEquals("[1.0]", m1.toString(), "error toString");
        m1.add(2.0);
        Assertions.assertEquals("[1.0, 2.0]", m1.toString(), "error toString");
    }

    @Test
    void testEqualsObject() {
        Assertions.assertFalse(m1.equals("toto"), "error equals class");
        Assertions.assertFalse(m1.equals(null), "error equals null");
        Assertions.assertTrue(m1.equals(m2), "error equals ensembles vide");
        m1.add(1.0);
        Assertions.assertFalse(m1.equals(m2), "error equals");
        m1.add(2.0);
        m2.add(2.0);
        m2.add(1.0);
        Assertions.assertTrue(m1.equals(m2), "error equals");
        m1.add(3.0);
        Assertions.assertFalse(m1.equals(m2), "error equals");
    }
}
