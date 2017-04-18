package com.nomenas.wrapperconcept.project;

/**
 * Created by naum.puroski on 14/04/2017.
 */

public class ExtendAndImplement extends SimpleClass implements SimpleInterface {
    public ExtendAndImplement() {create();};

    public native void method1();
    public native int method2(int value);

    protected native void create();
    protected native void delete();
}

