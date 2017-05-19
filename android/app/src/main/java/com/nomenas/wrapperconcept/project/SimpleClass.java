package com.nomenas.wrapperconcept.project;

public class SimpleClass extends Object {

    public enum Status {
        Item1,
        Item2,
        Item3;
    }

    public SimpleClass(int value) {
        create(value);
    }

    public native void method1();
    public native int method2(int value);
    public native String method3(int value, String text);

    public native Integer getObject();
    public native Integer getOwnedItem();
    public native Integer getItemTakeOwnership();

    public native int callMethodWithPtr(Integer obj, int value);
    public native int callMethodWithObj(Integer obj, int value);

    public native String getConstValue();

    public native Status getStatus();
    public native int setStatus(Status status);

    protected SimpleClass() {};
    protected native void create(int value);
    protected native void delete();
}
