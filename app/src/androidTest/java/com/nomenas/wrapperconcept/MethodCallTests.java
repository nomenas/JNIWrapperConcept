package com.nomenas.wrapperconcept;

import android.content.Context;
import android.support.test.InstrumentationRegistry;
import android.support.test.runner.AndroidJUnit4;

import com.nomenas.wrapperconcept.project.Callback;
import com.nomenas.wrapperconcept.project.CallbackTester;
import com.nomenas.wrapperconcept.project.LambdaCallback;
import com.nomenas.wrapperconcept.project.SimpleClass;

import org.junit.Test;
import org.junit.runner.RunWith;

import static org.junit.Assert.*;

/**
 * Instrumentation test, which will execute on an Android device.
 *
 * @see <a href="http://d.android.com/tools/testing">Testing documentation</a>
 */
@RunWith(AndroidJUnit4.class)
public class MethodCallTests {
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
        SimpleClass instance = new SimpleClass(4);

        SimpleClass ownedItem = instance.getOwnedItem();
        assertNotNull(ownedItem);
        assertEquals(2, ownedItem.method2(2));
        assertEquals("ownedItem 2", instance.method3(2, "ownedItem"));

        SimpleClass sharedItem = instance.getItemTakeOwnership();
        assertNotNull(sharedItem);
        assertEquals(3, ownedItem.method2(3));
        assertEquals("ownedItem 3", instance.method3(3, "ownedItem"));

        assertEquals(5, instance.callMethod(sharedItem, 5));
        String result1 = instance.getConstValue();
        String result2 = instance.getConstValue();
        assertEquals("const value", result1);
        assertEquals("const value", result2);
        assertEquals(result1.hashCode(), result2.hashCode());
    }
}
