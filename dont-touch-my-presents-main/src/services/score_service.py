import json

from paths import ROOT_DIR

score_file_path = ROOT_DIR / "best_score.json"
default_data = {"best": 0}


class ScoreService:
    @staticmethod
    def create_score_file_if_not_exist() -> None:
        if score_file_path.exists():
            return

        ScoreService.update_score_file(default_data)

    @staticmethod
    def load_score_file() -> dict:
        with open(score_file_path, mode="r", encoding="utf-8-sig") as file:
            return json.loads(file.read())

    @staticmethod
    def get_max_score() -> int:
        ScoreService.create_score_file_if_not_exist()
        data = ScoreService.load_score_file()

        return data.get("best")

    @staticmethod
    def update_score_file(data: dict):
        with open(score_file_path, mode="w", encoding="utf-8") as file:
            json.dump(data, file)

    @staticmethod
    def update_max_score(new_score):
        data = ScoreService.load_score_file()
        data["best"] = new_score
        ScoreService.update_score_file(data)
