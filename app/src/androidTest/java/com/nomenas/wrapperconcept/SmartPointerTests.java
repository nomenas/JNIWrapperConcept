package com.nomenas.wrapperconcept;

import android.support.test.runner.AndroidJUnit4;

import com.nomenas.wrapperconcept.project.Integer;
import com.nomenas.wrapperconcept.project.SmartPointers;

import org.junit.Test;
import org.junit.runner.RunWith;

import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertNotNull;

@RunWith(AndroidJUnit4.class)
public class SmartPointerTests {
    static {
        System.loadLibrary("native-lib");
    }

    @Test
    public void testGetValueFromSharedPointers() {
        Integer arg = SmartPointers.createSharedInteger(1);
        assertNotNull(arg);
        assertEquals(arg.value(), 1);
    }

    @Test
    public void testGetValueFromUniquePointers() {
        Integer arg = SmartPointers.createUniqueInteger(2);
        assertNotNull(arg);
        assertEquals(arg.value(), 2);
    }

    @Test
    public void testRowPointerConversion() {
        Integer arg1 = SmartPointers.createRowInteger(1);
        assertNotNull(arg1);
        Integer arg2 = SmartPointers.createRowInteger(2);
        assertNotNull(arg2);
        assertEquals(1, arg1.value());
        assertEquals(2, arg2.value());

        // test using row pointers for row pointers APIs
        Integer row_result = SmartPointers.sumRow(arg1, arg2);
        assertNotNull(row_result);
        assertEquals(3, row_result.value());

        // test using row pointers for smart pointers APIs
        Integer shared_result = SmartPointers.sumShared(arg1, arg2);
        assertNotNull(shared_result);
        assertEquals(3, shared_result.value());

        // test using row pointers for unique pointers APIs
        Integer unique_result = SmartPointers.sumUnique(arg1, arg2);
        assertNotNull(unique_result);
        assertEquals(3, unique_result.value());

        // check if both pointers used as unique_ptr are still valid
        assertEquals(1, arg1.value());
        assertEquals(2, arg2.value());
    }

    @Test
    public void testSharedPointerConversion() {
        Integer arg1 = SmartPointers.createSharedInteger(1);
        assertNotNull(arg1);
        Integer arg2 = SmartPointers.createSharedInteger(2);
        assertNotNull(arg2);
        assertEquals(1, arg1.value());
        assertEquals(2, arg2.value());

        // test using row pointers for row pointers APIs
        Integer row_result = SmartPointers.sumRow(arg1, arg2);
        assertNotNull(row_result);
        assertEquals(3, row_result.value());

        // test using row pointers for smart pointers APIs
        Integer shared_result = SmartPointers.sumShared(arg1, arg2);
        assertNotNull(shared_result);
        assertEquals(3, shared_result.value());

        // test using row pointers for unique pointers APIs
        Integer unique_result = SmartPointers.sumUnique(arg1, arg2);
        assertNotNull(unique_result);
        assertEquals(3, unique_result.value());
    }

    @Test
    public void testUniquePointerConversion() {
        Integer arg1 = SmartPointers.createUniqueInteger(1);
        assertNotNull(arg1);
        Integer arg2 = SmartPointers.createUniqueInteger(2);
        assertNotNull(arg2);
        assertEquals(1, arg1.value());
        assertEquals(2, arg2.value());

        // test using row pointers for row pointers APIs
        Integer row_result = SmartPointers.sumRow(arg1, arg2);
        assertNotNull(row_result);
        assertEquals(3, row_result.value());

        // test using row pointers for smart pointers APIs
        Integer shared_result = SmartPointers.sumShared(arg1, arg2);
        assertNotNull(shared_result);
        assertEquals(3, shared_result.value());

        // test using row pointers for unique pointers APIs
        Integer unique_result = SmartPointers.sumUnique(arg1, arg2);
        assertNotNull(unique_result);
        assertEquals(3, unique_result.value());
    }
}
