package com.nomenas.wrapperconcept;

import android.support.test.runner.AndroidJUnit4;

import com.nomenas.wrapperconcept.project.SingleInheritanceCustom;
import com.nomenas.wrapperconcept.project.SingleInheritance;

import org.junit.Test;
import org.junit.runner.RunWith;

import static org.junit.Assert.assertEquals;

@RunWith(AndroidJUnit4.class)
public class ExtendClassFromJavaTest {
    static {
        System.loadLibrary("native-lib");
    }

    private class UserExtendedSingleInheritance extends SingleInheritanceCustom {
        @Override
        public int java_overridable(){
            return 200;
        }
    }

    @Test
    public void testDefaultImplementation() {
        SingleInheritance obj = new SingleInheritance();
        assertEquals(obj.java_overridable(), 0);
    }

    @Test
    public void testOverridenImplementation() {
        SingleInheritance obj = new UserExtendedSingleInheritance();
        assertEquals(obj.java_overridable(), 200);
    }
}
