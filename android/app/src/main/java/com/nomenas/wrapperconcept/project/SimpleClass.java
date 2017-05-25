package com.nomenas.wrapperconcept.project;

import java.util.List;

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

    public final native List<Integer> getListOfElements();
    public final native int sum(List<Integer> list);

    public final native List<Integer> getSharedListOfElements();
    public final native int sumSharedList(List<Integer> list);

    protected SimpleClass() {};
    protected final native void create(int value);
    protected native void delete();
}
