from PyQt5.QtGui import QBrush
from PyQt5.QtGui import QColor
from PyQt5.QtGui import QPainter
from PyQt5.QtGui import QPalette
from PyQt5.QtGui import QPen
from PyQt5.QtWidgets import QApplication
from PyQt5.QtWidgets import QMessageBox
from PyQt5.QtWidgets import QPushButton
from PyQt5.QtWidgets import QVBoxLayout
from PyQt5.QtWidgets import QWidget
from scipy.special import binom
import sys

class Drawer(QWidget):
    def __init__(self):
        super().__init__()
        self.dots = []

        layout = QVBoxLayout()
        self.setLayout(layout)
        self.setFixedSize(1200, 900)
        self.show()

    def paintEvent(self, QPaintEvent):
        painter = QPainter(self)
        self.setPalette(QPalette(QColor(200, 250, 150)))
        painter.setBrush(QColor(100, 100, 100))
        vec = self.some()
        painter.setPen(QPen(QColor(200, 20, 20), 4))
        for i in range(len(vec) - 1):
            painter.drawLine(vec[i][0], vec[i][1], vec[i+1][0], vec[i+1][1])
        painter.setPen(QPen(QColor(20, 20, 200), 10))
        for i in self.dots:
            painter.drawPoint(i[0], i[1])
        from PyQt5.QtCore import Qt
        p = QPen(QColor(100, 100, 100))
        p.setStyle(Qt.DashLine)
        painter.setPen(p)
        for i in range(len(self.dots) - 1):
            painter.drawLine(self.dots[i][0], self.dots[i][1], self.dots[i+1][0], self.dots[i+1][1])

    def mousePressEvent(self, QMouseEvent):
        if len(self.dots) > 30:
            QMessageBox.about(self, 'Stop', 'It is good enough, stop please')
            return
        t = (QMouseEvent.pos().x(), QMouseEvent.pos().y())
        self.dots.append(t)
        self.update()

    def get_curve(self, ver):
        if not len(ver):
            return []
        res = []
        self.count = 200
        for i in range(self.count + 1):
            t = i/ self.count
            res.append(self.get_dot(ver, t))
        return res

    def get_dot(self, ver, t):
        if len(ver) == 1:
            return ver[0]
        res = []
        for i in range(len(ver) - 1):
            a, b = ver[i], ver[i + 1]
            r = (b[0] - a[0], b[1] - a[1])
            r = (r[0] * t, r[1] * t)
            x = a[0] + r[0]
            y = a[1] + r[1]
            res.append((x, y))
        return self.get_dot(res, t)

    def coef(self, n, i, t):
        return binom(n, i) * (t ** i) * ((1 - t) ** i)

    def some(self):
        dots = [(0.087526881720430105, 0.18961038961038962), (0.16086021505376341, 0.78961038961038965),
                (0.30752688172043013, 0.70909090909090899), (0.31462365591397851, 0.37142857142857139),
                (0.46602150537634418, 0.2233766233766234), (0.60559139784946248, 0.45714285714285713),
                (0.53225806451612923, 0.63896103896103895), (0.56301075268817224, 0.79740259740259734),
                (0.63161290322580665, 0.76103896103896096), (0.65053763440860224, 0.5896103896103897),
                (0.65526881720430108, 0.2805194805194805), (0.7427956989247313, 0.212987012987013),
                (0.77591397849462362, 0.30389610389610389), (0.77354838709677431, 0.42337662337662335),
                (0.76172043010752688, 0.52207792207792214), (0.79483870967741943, 0.41038961038961036),
                (0.79956989247311827, 0.34805194805194806), (0.79010752688172059, 0.212987012987013),
                (0.69075268817204316, 0.17662337662337663), (0.56064516129032271, 0.18701298701298702)]
        return self.get_curve(self.dots)

sys._excepthook = sys.excepthook

def my_exception_hook(exctype, value, traceback):
    print(exctype, value, traceback)
    sys._excepthook(exctype, value, traceback)
    sys.exit(1)
sys.excepthook = my_exception_hook

if __name__ == "__main__":
    app = QApplication([])
    d = Drawer()
    sys.exit(app.exec_())

