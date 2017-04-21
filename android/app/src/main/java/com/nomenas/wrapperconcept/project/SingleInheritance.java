package com.nomenas.wrapperconcept.project;

/**
 * Created by naum.puroski on 13/04/2017.
 */

public class SingleInheritance extends Object implements SimpleInterface {
    public SingleInheritance() {create();};

    public native void method1();
    public native int method2(int value);

    protected native void create();
    protected native void delete();
}
