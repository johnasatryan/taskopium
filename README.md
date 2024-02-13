# Taskopium

This Task Manager application is designed to help users efficiently manage their tasks with features like adding, viewing, and setting deadlines for tasks. It's built using the Qt framework for a rich graphical user interface, making task management both intuitive and accessible.

## Getting Started

Follow these instructions to get the Taskopium application running on your local machine for development, testing, or usage.

### Prerequisites

Before you begin, ensure you have the following installed:
- Qt 5.x (5.15 or later recommended) [Qt installation guide](https://www.qt.io/download)
- A C++ compiler compatible with C++11 or later

### Installing

To set up the project environment:

1. Clone the repository:
    ```bash
    git clone https://github.com/johnasatryan/taskopium.git
    ```

2. Navigate to the project directory:
    ```bash
    cd taskopium
    ```

3. Build the project using Qt Creator or command line (qmake):
    ```bash
    qmake && make
    ```
   Or, if using CMake:
    ```bash
    mkdir build && cd build
    cmake .. && make
    ```

4. Run the application:
    ```bash
    ./taskopium
    ```

## Features

- **Task Addition**: Add tasks with titles, descriptions, priorities, statuses, and deadlines.
- **Task Viewing**: View a list of added tasks along with their details.
- **Deadline Management**: Set and view deadlines using a calendar widget.

## Running the Tests

Currently, there are no automated tests written for this system.

## Deployment

This application can be deployed on desktop environments that support the Qt framework.

## Built With

- [Qt](https://www.qt.io/) - The GUI framework used for application development.

## Contributing

Contributions are what make the open-source community such an amazing place to learn, inspire, and create. Any contributions you make are **greatly appreciated**.

Please refer to [CONTRIBUTING.md](CONTRIBUTING.md) for our contribution guidelines.
).


## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details.

## Acknowledgments

- Hat tip to anyone whose code was used.
- Inspiration.
- The Qt Community for excellent documentation.

