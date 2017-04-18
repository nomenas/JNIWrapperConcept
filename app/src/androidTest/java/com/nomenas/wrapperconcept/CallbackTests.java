package com.nomenas.wrapperconcept;

import android.support.test.runner.AndroidJUnit4;

import com.nomenas.wrapperconcept.project.Callback;
import com.nomenas.wrapperconcept.project.CallbackTester;
import com.nomenas.wrapperconcept.project.LambdaCallback;

import org.junit.Test;
import org.junit.runner.RunWith;

import static org.junit.Assert.assertTrue;

@RunWith(AndroidJUnit4.class)
public class CallbackTests {
    static {
        System.loadLibrary("native-lib");
    }

    private class CallbackImpl implements Callback, LambdaCallback {
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
    public void testObjCallback() throws Exception {
        CallbackTester tester = new CallbackTester(14);

        CallbackImpl callback = new CallbackImpl();
        tester.do_callback((Callback) callback);
        assertTrue(callback.isCalled());
    }

    @Test
    public void testLambdaCallback() {
        CallbackTester tester = new CallbackTester(15);

        CallbackImpl lambdaCallback = new CallbackImpl();
        tester.do_callback((LambdaCallback) lambdaCallback);
        assertTrue(lambdaCallback.isCalled());
    }
}
