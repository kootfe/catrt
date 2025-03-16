# Cat.RT (Cat Runtime) Documentation

(Note: xyz is variable and can be anything)

Cat.RT is a runtime and compiler that allows coding in any language using a node-based structure. It is not just a game engine or any software-based runtime; it can be used for anything and acts as a universal runtime for all programming languages.

## Project Structure
Cat.RT uses a project folder as its configuration directory. The structure is as follows:

```plaintext
catrt/
├── plugins/
├── plugouts/
├── corenodes/
├── nodes/
├── node_configs/
```

## Node-Based System
Cat.RT operates using nodes. The main system acts as the CPU and handles logic processing. It connects to a **node manager**, which manages other nodes. Nodes can be organized hierarchically.

### Example Hierarchy
```plaintext
Game (Main Node)
│
├── GameNodeManager (Node Manager)
│   ├── EntityMechanics (Node)
│   │   ├── MobMechanics (Sub-node)
│   │   ├── PlayerMechanics (Sub-node)
│   ├── BlockMechanics (Node)
```

## Local and Web Compatibility
Cat.RT supports both local and web-based installations. Nodes function as modular components that interact dynamically. Example:

- A **KeyboardListener** node listens for keypresses.
- On pressing `W`, it sends the input to the node manager.
- The node manager sends the input to the main node, which decides what to do.
- After deciding, the main node sends data back to the node manager.
- The node manager checks the action and sends it to **PlayerMovement**, which moves the player.

## Plugouts and Modifications
Plugouts allow modifying nodes dynamically. They have their own lexer and can replace, remove, or disable nodes.

### Example Plugout File
```plaintext
// Example plugout file (nodename.xyz.pgo)
type=replace // Can be 'remove' or 'disable'
src="path/to/new.node" // Can be a web source too, like https://example.com/file.xyz
```

### Replacing Functions
```plaintext
type=replace
funcs = [
    {
        func = "funcname",
        src = "path/to/new_function.funcnode"
    }
]
```

## Core Nodes
Core nodes define main execution points and managers:

- `.mnode`: Defines main nodes (e.g., `main.mnode`, `core.mnode`).
- `.nmanager`: Defines node managers.
- `.node`: Defines standard nodes and their configurations.
- `.funcnode`: Automatically creates its node for functions.

## Project Configuration
Projects contain `ini`-based configurations.

## Multi-Language Support
Since Cat.RT only calls functions from nodes, it allows using multiple incompatible languages within the same project. Even core nodes and other nodes can be written in any language.

## SillyCatLoad
To optimize performance, SillyCatLoad enables partial reloads instead of restarting the entire system. Modified parts reload dynamically, allowing for:

- Hot-loading
- Hot-swapping
- Lazy-loading

## Conclusion
Cat.RT is a powerful runtime that enables flexible, modular, and multi-language project development with dynamic node-based execution.
