package com.nomenas.wrapperconcept.project;

public class SimpleClass extends Object {

    public SimpleClass() {
        create();
    }

    public native void method1();
    public native int method2(int value);
    public native String method3(int value, String text);

    protected native void create();
    protected native void delete();
}
