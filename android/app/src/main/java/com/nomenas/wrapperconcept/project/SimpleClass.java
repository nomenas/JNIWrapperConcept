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

    public final native void method1();
    public final native int method2(int value);
    public final native String method3(int value, String text);

    public final native Integer getObject();
    public final native Integer getOwnedItem();
    public final native Integer getItemTakeOwnership();

    public final native int callMethodWithPtr(Integer obj, int value);
    public final native int callMethodWithObj(Integer obj, int value);

    public final native String getConstValue();

    public final native Status getStatus();
    public final native int setStatus(Status status);

    protected SimpleClass() {};
    protected final native void create(int value);
    protected native void delete();
}
