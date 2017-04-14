package com.nomenas.wrapperconcept;

import android.content.Context;
import android.support.test.InstrumentationRegistry;
import android.support.test.runner.AndroidJUnit4;

import com.nomenas.wrapperconcept.project.SimpleInterface;
import com.nomenas.wrapperconcept.project.SingleInheritance;

import org.junit.Test;
import org.junit.runner.RunWith;

import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertNotNull;

@RunWith(AndroidJUnit4.class)
public class SimpleInheritanceTests {
    static {
        System.loadLibrary("native-lib");
    }

    @Test
    public void testInterface() {
        SimpleInterface obj = new SingleInheritance();
        assertNotNull(obj);
        SingleInheritance down_cast = (SingleInheritance) obj;
        assertNotNull(down_cast);
        SimpleInterface up_cast = (SimpleInterface) down_cast;
        assertNotNull(up_cast);

        // just method void methods in order to check if that is possible via all
        // interfaces. With each call internal counter of object is incremented for 1
        obj.method1();
        down_cast.method1();
        up_cast.method1();

        // we are changing same object all the time
        assertEquals(obj.method2(1), 5);
        assertEquals(down_cast.method2(1), 6);
        assertEquals(down_cast.method2(1), 7);
    }

}
