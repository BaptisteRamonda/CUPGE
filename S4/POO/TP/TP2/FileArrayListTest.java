package tp2;

import org.junit.jupiter.api.AfterEach;
import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

class FileArrayListTest {
    private FileArrayList f1;
    private FileArrayList f2;

    @BeforeEach
    void setUp() {
        f1 = new FileArrayList();
        f2 = new FileArrayList();
    }

    @AfterEach
    void tearDown() {
        f1 = null;
        f2 = null;
        System.gc();
    }

    @Test
    void testAdd() {
        f1.add(0);
        Assertions.assertEquals(0, f1.get(), "Error add");
        f1.add(1);
        Assertions.assertEquals(0, f1.get(), "Error add");
    }

    @Test
    void testRemove() {
        f1.add(0);
        f1.remove();
        Assertions.assertEquals(0, f1.size(), "Error remove");
        f1.add(0);
        f1.add(1);
        f1.remove();
        Assertions.assertEquals(1, f1.size(), "Error remove");
        Assertions.assertEquals(1, f1.get(), "Error remove");
    }

    @Test
    void testIsEmpty() {
        Assertions.assertTrue(f1.isEmpty(), "Error isEmpty");
        f1.add(0);
        Assertions.assertFalse(f1.isEmpty(), "Error isEmpty");
        f1.remove();
        Assertions.assertTrue(f1.isEmpty(), "Error isEmpty");
    }

    @Test
    void testSize() {
        Assertions.assertEquals(0, f1.size(), "Error size");
        f1.add(0);
        Assertions.assertEquals(1, f1.size(), "Error size");
        f1.add(1);
        Assertions.assertEquals(2, f1.size(), "Error size");
        f1.remove();
        Assertions.assertEquals(1, f1.size(), "Error size");
        f1.remove();
        Assertions.assertEquals(0, f1.size(), "Error size");
    }

    @Test
    void testGet() {
        try {
            f1.get();
            Assertions.fail("Error get(), no assertion with empty queue");
        } catch (AssertionError ignored) {

        }
        f1.add(0);
        Assertions.assertEquals(0, f1.get(), "Error get");
        f1.add(1);
        Assertions.assertEquals(0, f1.get(), "Error get");
        f1.remove();
        Assertions.assertEquals(1, f1.get(), "Error get");
        f1.add(0);
        Assertions.assertEquals(1, f1.get(), "Error get");
    }

    @Test
    void testToString() {
        Assertions.assertEquals("[]", f1.toString(), "Error toString");
        f1.add(0);
        Assertions.assertEquals("[0.0]", f1.toString(), "Error toString");
        f1.add(1);
        Assertions.assertEquals("[0.0, 1.0]", f1.toString(), "Error toString");
        f1.remove();
        Assertions.assertEquals("[1.0]", f1.toString(), "Error toString");
        f1.remove();
        Assertions.assertEquals("[]", f1.toString(), "Error toString");
    }

    @SuppressWarnings("unlikely-arg-type")
    @Test
    void testEqualsObject() {
        Assertions.assertFalse(f1.equals(null), "Error equals");
        Assertions.assertFalse(f1.equals("hello"), "Error equals");
        Assertions.assertTrue(f1.equals(f2), "Error equals");
        f1.add(0);
        Assertions.assertFalse(f1.equals(f2), "Error equals");
        f1.add(1);
        f2.add(0);
        f2.add(1);
        Assertions.assertTrue(f1.equals(f2), "Error equals");
        f1.remove();
        f2.remove();
        Assertions.assertTrue(f1.equals(f2), "Error equals");
    }
}
