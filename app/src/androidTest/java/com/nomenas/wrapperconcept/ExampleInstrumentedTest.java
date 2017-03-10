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
public class ExampleInstrumentedTest {
    static {
        System.loadLibrary("native-lib");
    }

    @Test
    public void useAppContext() throws Exception {
        // Context of the app under test.
        Context appContext = InstrumentationRegistry.getTargetContext();

        assertEquals("com.nomenas.wrapperconcept", appContext.getPackageName());
    }

    @Test
    public void testCreateClassImplInstance() throws Exception {
        SimpleClass instance = new SimpleClass(4);
        instance.method1();
        assertEquals(1, instance.method2(1));
        assertEquals("test 1", instance.method3(1, "test"));

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

    private class CallbackImpl implements Callback, LambdaCallback{
        boolean _called = false;

        @Override
        public void somethingHappened(int arg) {
            System.out.println("***** somethingHappend ->" + arg);
            _called = true;
        }

        public boolean isCalled() {
            return _called;
        }

        @Override
        public void handle(int arg) {
            System.out.println("\"***** handle ->" + arg);
            _called = true;
        }
    }

    @Test
    public void testCallbacks() throws Exception {

        CallbackTester tester = new CallbackTester(14);

        CallbackImpl callback = new CallbackImpl();
        tester.do_callback((Callback) callback);
        assertTrue(callback.isCalled());

        CallbackImpl lambdaCallback = new CallbackImpl();
        tester.do_callback((LambdaCallback) lambdaCallback);
        assertTrue(lambdaCallback.isCalled());
    }
}
