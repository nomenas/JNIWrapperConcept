package com.nomenas.wrapperconcept.project;

abstract class Object {
    private long reference = 0;

    public void setReference(long reference) {
        this.reference = reference;
    }

    public long getReference() {
        return reference;
    }

    protected void finalize() {
        delete();
    }

    protected abstract void delete();
}
