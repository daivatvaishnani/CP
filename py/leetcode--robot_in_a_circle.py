class Coordinate:
    def __init__(self, x, y, d):
        self.x = x
        self.y = y
        self.d = d


class Robot:
    def __init__(self, position):
        self.position = position

    def process_command(self, position, command):
        if command == 'G':
            position.x += (position.d & 1)*(1 if position.d == 1 else -1)
            position.y += (1 - position.d & 1)*(1 if position.d == 0 else -1)
        elif command == 'L':
            position.d = (position.d + 1) % 4
        else:
            position.d = (position.d + 3) % 4
        return position

    def process_instructions(self, position, instructions):
        for command in instructions:
            self.process_command(position, command)
        print("status: {0}".format(self.status()))
        return position

    def status(self):
        return "[{0},{1},{2}]".format(self.position.x, self.position.y, self.position.d)


class SMRUTI:
    def isRobotBounded(self, instructions):
        robot = Robot(Coordinate(0, 0, 1))
        # print("starting status: {0}".format(robot.status()))
        robot.process_instructions(robot.position, instructions)
        print(robot.status())
        return robot.position.d != 1 or (robot.position.x == 0 and robot.position.y == 0)


class Tester:
    def __init__(self, test_data):
        self.test_data = test_data

    def run(self):
        num = 1
        for test_input, expected_output in self.test_data.items():
            print("================================")
            print("Running Test Case #{0}".format(num))
            print("================================")
            test_status = "Passed!"
            solution_output = None
            try:
                solution_output = SMRUTI().isRobotBounded(test_input)
                assert solution_output == expected_output
            except AssertionError:
                test_status = "Failed!"
            finally:
                print("SMRUTI: {0}, Expected: {1}".format(
                    solution_output, expected_output))
                print(test_status)
            num += 1


test_data = {
    "GGLLGG": True,
    "GG": False,
    "GL": True,
    "GGLGRGGGLGGLGRGGRGLGG": True
}

Tester(test_data).run()
