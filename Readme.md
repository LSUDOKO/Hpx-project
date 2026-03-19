
# Parallel Matrix Multiplication with HPX

A modular, component-based implementation of parallel matrix multiplication built using the **HPX (High Performance ParalleX)** C++ runtime library. This project demonstrates high-performance distributed computing patterns, including asynchronous actions, global address space management, and task-based parallelism.

---

##  Overview

This project implements matrix multiplication ($C = A \times B$) by wrapping the computation logic into a distributed **HPX Component**. By utilizing HPX actions, the system can execute the computation on any locality (cluster node) within a global address space.

### Key HPX Features Used:

- **Asynchronous Actions**: Remote procedure calls (RPC) made locality-agile through AGAS  
- **Components**: Object-oriented distributed state management  
- **Futures**: Non-blocking synchronization for lazy evaluation  
- **Parallel Algorithms**: Using `hpx::execution::par` for fine-grained task scheduling across thread pools  

---

## Architecture

The system follows a modular **Client-Server** architecture as illustrated in the system workflows below:

### Distributed Execution Cycle

<img width="837" height="765" alt="swappy-20260320-014231" src="https://github.com/user-attachments/assets/29ae380d-22ed-4068-aa95-69cdbbc52fed" />

### System Workflow


<img width="593" height="783" alt="swappy-20260320-014250" src="https://github.com/user-attachments/assets/a3943b65-7dea-48cd-a43b-03c84f25bed5" />

---

## 📂 Project Structure

```text
.
├── CMakeLists.txt        # Build configuration using HPX macros
├── components/           # Server-side logic
│   ├── matrix_ops.hpp    # Component & Action definitions
│   └── matrix_ops.cpp    # Parallel implementation
├── client/               # User-facing orchestration
│   └── main.cpp          # Runtime initialization and async invocation
└── Readme.md             # Documentation
