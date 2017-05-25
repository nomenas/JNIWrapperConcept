package com.nomenas.wrapperconcept;

import android.content.Context;
import android.support.test.InstrumentationRegistry;
import android.support.test.runner.AndroidJUnit4;

import com.nomenas.wrapperconcept.project.Callback;
import com.nomenas.wrapperconcept.project.CallbackTester;
import com.nomenas.wrapperconcept.project.Integer;
import com.nomenas.wrapperconcept.project.LambdaCallback;
import com.nomenas.wrapperconcept.project.SimpleClass;

import org.junit.Test;
import org.junit.runner.RunWith;

import java.util.List;

import static org.junit.Assert.*;

/**
 * Instrumentation test, which will execute on an Android device.
 *
 * @see <a href="http://d.android.com/tools/testing">Testing documentation</a>
 */
@RunWith(AndroidJUnit4.class)
public class SimpleClassTests {
    static {
        System.loadLibrary("native-lib");
    }

    @Test
    public void testCreateAndCallSimpleMethods() throws Exception {
        SimpleClass instance = new SimpleClass(4);
        instance.method1();
        assertEquals(1, instance.method2(1));
        assertEquals("test 1", instance.method3(1, "test"));
    }

    @Test
    public void testOwnership() {
        SimpleClass instance = new SimpleClass(2);

        Integer ownedItem = instance.getOwnedItem();
        assertNotNull(ownedItem);
        assertEquals(2, ownedItem.value());
        assertEquals(7, instance.callMethodWithPtr(ownedItem, 5));

        Integer sharedItem = instance.getItemTakeOwnership();
        assertNotNull(sharedItem);
        assertEquals(2, sharedItem.value());
        assertEquals(10, instance.callMethodWithPtr(sharedItem, 8));
    }

    @Test
    public void testReturnAndUseObject() {
        SimpleClass instance = new SimpleClass(4);

        Integer obj = instance.getObject();
        assertNotNull(obj);
        assertEquals(4, obj.value());
        assertEquals(9, instance.callMethodWithObj(obj, 5));
    }

    @Test
    public void testGetAndCache() {
        SimpleClass instance = new SimpleClass(4);
        String result1 = instance.getConstValue();
        String result2 = instance.getConstValue();
        assertEquals("const value", result1);
        assertEquals("const value", result2);
        assertEquals(result1.hashCode(), result2.hashCode());
    }

    @Test
    public void testEnum() {
        SimpleClass instance = new SimpleClass(4);
        SimpleClass.Status result = instance.getStatus();
        assertTrue(result.equals(SimpleClass.Status.Item2));
        assertEquals(1, instance.setStatus(result));
    }

    @Test
    public void testArray() {
        SimpleClass instance = new SimpleClass(5);
        List<Integer> result = instance.getListOfElements();
        assertNotNull(result);
        assertEquals(result.size(), 4);
        assertEquals(result.get(0).value(), 0);
        assertEquals(result.get(1).value(), 1);
        assertEquals(result.get(2).value(), 2);
        assertEquals(result.get(3).value(), 3);

        assertEquals(instance.sum(result), 6);
    }

    @Test
    public void testSharedArray() {
        SimpleClass instance = new SimpleClass(5);
        List<Integer> result = instance.getSharedListOfElements();
        assertNotNull(result);
        assertEquals(result.size(), 4);
        assertEquals(result.get(0).value(), 0);
        assertEquals(result.get(1).value(), 1);
        assertEquals(result.get(2).value(), 2);
        assertEquals(result.get(3).value(), 3);

        assertEquals(instance.sumSharedList(result), 6);
    }
}
