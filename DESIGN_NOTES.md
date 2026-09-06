# Task 2 — Notes on the implementation

## Bugs fixed in the Visual Paradigm-generated stub (not just TODOs filled in)
1. **Private inheritance everywhere it should be public**: `EmergencyUnit`, `FireEngine`,
   `Ambulance`, `PoliceUnit`, `RescueUnit`, `EmergencyIterator`, `AllUnitsIterator`,
   `AvailableUnitsIterator`, `TypeFilterIterator`. Visual Paradigm's default C++ export
   uses private inheritance unless you set it explicitly on the diagram. Left as-is, none
   of these could be stored/used through their base class pointer — the Composite and
   Iterator patterns would not have compiled the way the design needs.
2. **`EmergencyGroup` was missing its `children` vector** — declared in the UML, absent
   from the generated header.
3. **Singleton pattern was broken on every State class**: generated code declared a
   non-static method literally named `static_getInstance`, which is not how you write a
   static factory method in C++. Rewrote each with a private constructor, a private
   `static X* instance;`, and a real `static X* getInstance();`.
4. **`PoliceUnit` had a field and a method both named `hasK9`** — flat compile error.
   Renamed the field to `hasK9Unit`.
5. **Mangled field names**: `Ambulance`'s `int_patientCapacity`/`int_medicalSupplies` →
   `patientCapacity`/`medicalSupplies`. `TypeFilterIterator`'s `int string_wantedType` →
   `string wantedType`.
6. **Dead code in `UnitState`**: every concrete state re-declared a non-virtual `cancel()`
   that could never actually override anything, since the base declaration also wasn't
   virtual. Made the base version `virtual` with one shared implementation and removed
   the pointless redeclarations.
7. **Header include cycle**: fixed by forward-declaring `EmergencyComponent`/
   `EmergencyIterator` wherever only a pointer is used, instead of fully including.

## Deviation from the UML you'll want to mirror in the diagram (Rule 9)
`EmergencyComponent` gained three methods not on the current diagram:
- `bool isAvailable()`
- `string getUnitType()`
- `void populate(vector<EmergencyComponent*>& list)`

Why: Composite + Iterator + Decorator can only cooperate here without a single
`dynamic_cast` or type-check (which Rule 8 forbids) if the base `Component` interface
exposes whatever the traversal needs to ask of *any* node — leaf, group, or decorated
leaf — without knowing which one it actually is. `populate()` is the actual
Composite/Iterator handshake: a group recurses into its children; a leaf or decorated
item adds itself. No iterator ever touches `EmergencyGroup`'s internal vector directly
(Rule 7).

## Traversal-modification policy (needed for Task 3/4 write-up)
**Snapshot traversal.** `buildList()` walks the tree once, at iterator-construction time,
and copies the relevant pointers into the iterator's own vector. A later
`addChild`/`removeChild`/`transferChild` on the live tree does not retroactively affect
an iterator that already exists — it keeps iterating its original snapshot. Consequence:
don't delete a component while a live iterator might still hold a pointer to it; finish
or discard the iterator first.

## Valgrind
`still reachable: 48 bytes in 6 blocks`, `definitely lost: 0`. The 6 blocks are the state
singletons — never deleted, by design (Task 1, ownership rule: singletons have no
per-instance data, so they're created once and live for the process's lifetime). "Still
reachable" (not "definitely lost") is the correct outcome for that design and is worth
citing directly in Task 5.

## demo_main.cpp
This is a validation harness I used to prove the model works — 4-level hierarchy, two
independent iterators, a type filter, full state lifecycle including one invalid
transition, a stacked decorator, and a runtime structural change. It's not a Task 3
deliverable (that's not my assigned task) but it's a real working example your teammate
doing Task 3 can borrow from or extend for the actual application scenarios.
