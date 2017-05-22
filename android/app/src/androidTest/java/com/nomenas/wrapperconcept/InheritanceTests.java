package com.nomenas.wrapperconcept;

import android.support.test.runner.AndroidJUnit4;

import com.nomenas.wrapperconcept.project.MultipleInheritance;
import com.nomenas.wrapperconcept.project.SimpleClass;
import com.nomenas.wrapperconcept.project.SimpleInterface;
import com.nomenas.wrapperconcept.project.SingleInheritance;
import com.nomenas.wrapperconcept.project.SingleInheritanceExt;

import org.junit.Test;
import org.junit.runner.RunWith;

import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertNotNull;

@RunWith(AndroidJUnit4.class)
public class InheritanceTests {
    static {
        System.loadLibrary("native-lib");
    }

    @Test
    public void testSingleInheritance() {
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

    @Test
    public void testSingleInheritanceExt() {
        SimpleInterface obj_interface = new SingleInheritanceExt();
        assertNotNull(obj_interface);
        SingleInheritance base_class_cast = (SingleInheritance) obj_interface;
        assertNotNull(base_class_cast);
        SingleInheritanceExt obj = (SingleInheritanceExt) obj_interface;
        assertNotNull(obj);

        // just method void methods in order to check if that is possible via all
        // interfaces. With each call internal counter of object is incremented for 1
        obj.method1();
        base_class_cast.method1();
        obj_interface.method1();

        // we are changing same object all the time
        assertEquals(obj.method2(1), 6);
        assertEquals(base_class_cast.method2(1), 7);
        assertEquals(obj_interface.method2(1), 8);
    }

    @Test
    public void testMultipleInheritance() {
        MultipleInheritance obj = new MultipleInheritance();
        assertEquals(2, obj.method2(2));

        // second inheritance is converted to aggregation
        assertEquals(5, obj.baseClassMethod());

        // up cast to simple class and check if all method are accessable thru that interface
        SimpleClass simpleClass = (SimpleClass) obj;
        assertEquals(2, simpleClass.method2(2));
    }
}
