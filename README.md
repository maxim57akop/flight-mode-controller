# Flight Mode Controller

Small C project that models basic drone flight mode transitions.

## What It Does

- Stores the current drone flight mode.
- Allows only safe mode transitions.
- Rejects invalid transitions.
- Shows how a simple state machine works.

## What I Practice

- `enum`
- `switch`
- Functions
- State machines
- Safety rules

## Build And Run

```sh
make
./flight-mode-controller
```

## Supported Modes

```text
IDLE -> TAKEOFF -> FLYING -> LANDING -> IDLE
Any mode -> ERROR
ERROR -> IDLE
```
