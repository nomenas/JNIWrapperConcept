package com.nomenas.wrapperconcept;

import android.support.test.runner.AndroidJUnit4;

import com.nomenas.wrapperconcept.project.Integer;
import com.nomenas.wrapperconcept.project.SmartPointers;

import org.junit.Test;
import org.junit.runner.RunWith;

import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertNotNull;
import static org.junit.Assert.assertTrue;

@RunWith(AndroidJUnit4.class)
public class SmartPointerTests {
    static {
        System.loadLibrary("native-lib");
    }

    @Test
    public void testRowPointerConversion() {
        Integer arg1 = SmartPointers.createRowInteger(1);
        assertNotNull(arg1);
        Integer arg2 = SmartPointers.createRowInteger(2);
        assertNotNull(arg2);
        assertEquals(1, arg1.value());
        assertEquals(2, arg2.value());

        // test calling method using row pointers
        Integer row_result = SmartPointers.sumRow(arg1, arg2);
        assertNotNull(row_result);
        assertEquals(3, row_result.value());
    }

    @Test
    public void testSharedPointerConversion() {
        assertTrue(false);
    }

    @Test
    public void testUniquePointerConversion() {
        assertTrue(false);
    }
}
