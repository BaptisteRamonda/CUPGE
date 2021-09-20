package tp1;

import org.junit.jupiter.api.AfterEach;
import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;


class MaPileEntiersTest {
    private MaPileEntiers p1;
    private MaPileEntiers p2;

    @BeforeEach
    void setUp() throws Exception {
        p1 = new MaPileEntiers(10);
        p2 = new MaPileEntiers(9);
    }

    @AfterEach
    void tearDown() throws Exception {
        p1 = null;
        p2 = null;
        System.gc();
    }

//	/**
//	 * Test method for {@link piles.MaPileEntiers#hashCode()}.
//	 */
//	@Test
//	void testHashCode() {
//		Assertions.assertEquals("HashCode error", 0, p1.hashCode());
//	}

    @Test
    void testMaPileEntiers() {
        Assertions.assertTrue(p1.size() == 0 && p1.capacity() == 10, "constructor error");
    }

    @Test
    void testAdd() {
        p1.add(1);
        Assertions.assertEquals(1, p1.get(), "add error");
    }

    @Test
    void testRemove() {
        Assertions.assertFalse(p1.remove(), "add error");
        p1.remove();
        Assertions.assertEquals(0, p1.size(), "add error");

        p1.add(1);
        p1.add(2);
        p1.remove();
        Assertions.assertEquals(1, p1.size(), "add error");
    }

    @Test
    void testGet() {
        p1.add(1);
        Assertions.assertEquals(1, p1.get(), "get error");
        try {
            int v = p1.get();
        } catch (Error e) {
            System.out.println("test of get() on an empty stack have to generate your Assertions.assertion");
        }
    }

    @Test
    void testSize() {
        Assertions.assertEquals(0, p1.size(), "size error");
        p1.add(1);
        Assertions.assertEquals(1, p1.size(), "size error");
    }

    @Test
    void testCapacity() {
        if (p1.capacity() != 10) {
            Assertions.fail("capacity error" + " p1 : " + p1 + " capacity : " + p1.capacity());
        }
        for (int i = 0; i < 5; i++) {
            p1.add(i);
        }
        if (p1.capacity() != 10)
            Assertions.fail("capacity error" + " p1 : " + p1 + " capacity : " + p1.capacity());
    }


    @Test
    void testIsFull() {
        int i = 0;
        Assertions.assertFalse(p1.isFull(), "error isFull");
        p1.add(i++);
        while (!p1.isFull())
            p1.add(i++);
        Assertions.assertTrue(p1.isFull(), "error isFull");
    }

    @Test
    void testIsEmpty() {
        Assertions.assertTrue(p1.isEmpty(), "Error isEmpty");
        p1.add(0);
        Assertions.assertFalse(p1.isEmpty(), "Error isEmpty");
    }

    @Test
    void testEqualsObject() {
        if (!p1.equals(p2))
            Assertions.fail("equals error" + " p1 : " + p1 + " p2 : " + p2);

        for (int i = 1; i < 5; i++) {
            p1.add(i);
            p2.add(i);
        }
        if (!p1.equals(p2))
            Assertions.fail("equals error" + " p1 : " + p1 + " p2 : " + p2);
        p2.remove();
        if (p1.equals(p2))
            Assertions.fail("equals error" + " p1 : " + p1 + " p2 : " + p2);
        p2.add(-1);
        if (p1.equals(p2))
            Assertions.fail("equals error" + " p1 : " + p1 + " p2 : " + p2);
    }

    @Test
    void testToString() {
        Assertions.assertTrue(p1.toString().equals("[]"), "toString empty stack");
        p1.add(1);
        Assertions.assertTrue(p1.toString().equals("[1]"), "toString stack with an element");
        p1.add(2);
        Assertions.assertTrue(p1.toString().equals("[1, 2]"), "toString stack with 2 elements");
    }

}
