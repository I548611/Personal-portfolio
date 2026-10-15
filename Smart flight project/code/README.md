Smart Flight Code — Ownership & Changes

Summary
- Replaced raw owning pointers with `std::unique_ptr` for GPS and motor objects.
- Factory functions `createGps()` and `createMotor()` now return `std::unique_ptr`.
- `drone.cpp` now holds `std::unique_ptr` instances and passes references to `StartDrone`/`StopDrone`.

Ownership model
- Unique ownership: each created GPS or motor is owned by a single `std::unique_ptr` in `main()`.
- Factories transfer ownership to the caller. The caller is responsible for storing the returned `unique_ptr`.
- `StartDrone` and `StopDrone` accept references; they do not take ownership.

Why `unique_ptr`?
- The original code used `new`/`delete`, which is error-prone. `std::unique_ptr` provides automatic RAII cleanup.
- `unique_ptr` is the right choice when ownership is exclusive and objects have a single owner.

If shared ownership is needed
- If multiple components need to share the same motor or GPS instance, replace `std::unique_ptr` with `std::shared_ptr` and update factory functions accordingly.

Files changed (high level)
- IGps.h — factory now returns `std::unique_ptr<IGps>` and includes ownership comment.
- IMotor.h — factory now returns `std::unique_ptr<IMotor>` and includes ownership comment.
- fakeGps.cpp / fakeMotor.cpp — factories updated to return `std::unique_ptr`.
- drone.cpp — uses `std::unique_ptr` and passes references to `StartDrone`/`StopDrone`.

Build
- From the project root run:

```bash
make
```

Notes
- No API semantic changes beyond the factory return type and `StartDrone`/`StopDrone` parameter types (now references rather than pointers).
- Let me know if you want the factories to return `shared_ptr` instead, or if you want inline comments added to additional files.
