package com.nomenas.wrapperconcept.project;

public class SimpleClass extends Object {

    public SimpleClass(int value) {
        create(value);
    }

    public native void method1();
    public native int method2(int value);
    public native String method3(int value, String text);

    public native SimpleClass getObject();
    public native SimpleClass getOwnedItem();
    public native SimpleClass getItemTakeOwnership();

    public native int callMethod(SimpleClass obj, int value);
    public native int testObjectArgMethod(SimpleClass obj, int value);

    public native String getConstValue();

    protected SimpleClass() {};
    protected native void create(int value);
    protected native void delete();
}
